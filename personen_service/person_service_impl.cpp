#include "person_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"

person_service_impl::person_service_impl(person_repository &repo) : repo(repo) {

}

void person_service_impl::speichern(person &p) {
    if(p.GetVorname().length() < 2) {
        throw personen_service_exception{"Vorname zu kurz"};
    }
    if(p.GetNachname().length() < 2) {
        throw personen_service_exception{"Nachname zu kurz"};
    }
    if(p.GetVorname() == "Atilla") {
        throw personen_service_exception{"WTF Vorname"};
    }
    try {
        bool exists = findePersonMitId(p.GetId()).has_value();
        if(exists) {
            repo.update(p);
        } else {
            repo.save(p);
        }
    } catch(repository_exception &e) {
        throw personen_service_exception(e.what());
    }
}

void person_service_impl::speichern(std::string vorname, std::string nachname) {
    person p{"99", vorname, nachname};
    speichern(p);
}

std::optional<person> person_service_impl::findePersonMitId(std::string id) {
    try {
        return repo.find_by_id(id);
    } catch (repository_exception &ex) {
        return std::nullopt;
    }
}


