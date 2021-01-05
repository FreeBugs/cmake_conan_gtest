#pragma once

#include <stdexcept>
#include <string>

class personen_service_exception :
        public std::runtime_error {
public:
    explicit personen_service_exception(const std::string &message)
            : runtime_error(message) {};
};

