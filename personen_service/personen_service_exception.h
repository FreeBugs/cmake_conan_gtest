#pragma once

#include <stdexcept>

class personen_service_exception :
        public std::runtime_error {
public:
    personen_service_exception(char const *const message);
};

