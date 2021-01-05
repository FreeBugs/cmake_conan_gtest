#include "person_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"

person_service_impl::person_service_impl(person_repository &repo) : repo(repo) {

}

void person_service_impl::speichern(person &p) {
    if(p.GetVorname().length() < 3) {
        throw personen_service_exception{"Vorname zu kurz"};
    }
    if(p.GetNachname().length() < 3) {
        throw personen_service_exception{"Nachname zu kurz"};
    }
    if(p.GetVorname() == "Atilla") {
        throw personen_service_exception{"WTF Vorname"};
    }
    try {
        repo.save(p);
    } catch(repository_exception &e) {
        throw personen_service_exception(e.what());
    }
}


std::optional<person> person_service_impl::findePersonMitId(std::string id) {
    try {
        return repo.find_by_id(id);
    } catch (repository_exception &ex) {
        return std::nullopt;
    }
}
