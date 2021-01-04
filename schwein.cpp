#include "schwein.hpp"
#include <stdexcept>

tiere::schwein::schwein(const std::string name) : name_(name), gewicht_(10) {
    if("Elsa" == name) {
        throw std::invalid_argument("No Elsa!");
    }
}

void tiere::schwein::fressen() {
    gewicht_++;
}

void tiere::schwein::set_name(std::string name) {
    if (name == "Elsa") throw std::invalid_argument("Name ist nicht erlaubt!");
    this->name_ = name;
}

std::string tiere::schwein::get_name() const {
    return name_;
}

int tiere::schwein::get_gewicht() const {
    return gewicht_;
}

std::ostream &tiere::operator<<(std::ostream &out, const schwein &schwein) {
    out << "Schwein: Name=";
    out << schwein.get_name();
    out << ", Gewicht=";
    out << schwein.get_gewicht();
    return out;


}
