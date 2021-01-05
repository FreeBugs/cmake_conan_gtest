#pragma once

#include <string>
#include "person_repository.h"
#include "person.h"
#include "antipath_checker.hpp"
#include <optional>

class person_service_impl {

private:
    person_repository &repo;
    antipath_checker &checker;


public:

    person_service_impl(person_repository &repo, antipath_checker &checker);

    void speichern(person &p);

    void speichern(std::string vorname, std::string nachname);

    std::optional<person> findePersonMitId(std::string id);
};

