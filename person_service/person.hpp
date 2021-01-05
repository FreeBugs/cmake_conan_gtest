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
        this->id = std::move(id);
    }

    void SetVorname(std::string vorname) {
        this->vorname = std::move(vorname);
    }

    void SetNachname(std::string nachname) {
        this->nachname = std::move(nachname);
    }

    [[nodiscard]] std::string GetVorname() const {
        return this->vorname;
    }

    [[nodiscard]] std::string GetNachname() const {
        return this->nachname;
    }

    [[nodiscard]] std::string GetId() const {
        return this->id;
    }
};

