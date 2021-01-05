#include "person_service_impl.hpp"

#include <utility>
#include "person_service_exception.hpp"
#include "repository_exception.hpp"

person_service_impl::person_service_impl(person_repository &repo,
                                         antipath_checker &checker) : repo(repo),
                                                                      checker(checker) {
}

void person_service_impl::speichern(person &p) {
    if (p.GetVorname().length() < 2) {
        throw person_service_exception{"Vorname zu kurz"};
    }
    if (p.GetNachname().length() < 2) {
        throw person_service_exception{"Nachname zu kurz"};
    }
    if (checker.is_antipath(p.GetVorname())) {
        throw person_service_exception{"WTF Vorname"};
    }
    try {
        bool exists = findePersonMitId(p.GetId()).has_value();
        if (exists) {
            repo.update(p);
        } else {
            repo.save(p);
        }
    } catch (repository_exception &e) {
        throw person_service_exception(e.what());
    }
}

void person_service_impl::speichern(std::string vorname, std::string nachname) {
    person p{"99", std::move(vorname), std::move(nachname)};
    speichern(p);
}

std::optional<person> person_service_impl::findePersonMitId(std::string id) {
    try {
        return repo.find_by_id(id);
    } catch (repository_exception &ex) {
        return std::nullopt;
    }
}


