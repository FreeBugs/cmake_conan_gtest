#include "person_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"

person_service_impl::person_service_impl(person_repository &repo) : repo(repo) {

}

void person_service_impl::speichern(person &p) {
    repo.save(p);
}


std::optional<person> person_service_impl::findePersonMitId(std::string id) {
    try {
        return repo.find_by_id(id);
    } catch (repository_exception &ex) {
        return std::nullopt;
    }
}
