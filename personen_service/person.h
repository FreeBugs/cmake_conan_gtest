#pragma once

#include <string>
#include <utility>

class person {
private:
    std::string id;
    std::string vorname;
    std::string nachname;

public:
    person() : id(""), vorname("John"), nachname("Doe") {}

    person(std::string id, std::string vorname, std::string nachname) : id(std::move(id)), vorname(std::move(vorname)),
                                                                        nachname(std::move(nachname)) {}

    void SetId(std::string id) {
        this->id = id;
    }

    void SetVorname(std::string vorname) {
        this->vorname = vorname;
    }

    void SetNachname(std::string nachname) {
        this->nachname = nachname;
    }

    std::string GetVorname() const {
        return this->vorname;
    }

    std::string GetNachname() const {
        return this->nachname;
    }

    std::string GetId() const {
        return this->id;
    }
};

