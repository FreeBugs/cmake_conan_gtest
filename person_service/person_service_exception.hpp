#pragma once

#include <stdexcept>
#include <string>

class person_service_exception :
        public std::runtime_error {
public:
    explicit person_service_exception(const std::string &message)
            : runtime_error(message) {};
};

