#include "dependency_to_fake.hpp"

string dependency_to_fake::get_firstname() const
{
    return "John";
}


string dependency_to_fake::get_lastname()
{
    return "Doe";
}
long dependency_to_fake::calculate(const int value) const
{
    return value * value;
}