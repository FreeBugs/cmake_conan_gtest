#include "personen_service_exception.h"

personen_service_exception::personen_service_exception(char const *const message) : std::runtime_error(message) {
}
