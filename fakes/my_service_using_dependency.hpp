#pragma once
#include "dependency_to_fake.hpp"

class my_service_using_dependency
{
private:
    dependency_to_fake dependency_;

public:
    my_service_using_dependency() = default;

    string first_method_under_test() const
    {
        return dependency_.get_firstname() + " Hallo";
    }

    string second_method_under_test() const
    {
        return dependency_to_fake::get_lastname() + " Hallo";
    }

    int third_method_under_test(const int x) const
    {
        return dependency_.calculate(x);
    }
};
