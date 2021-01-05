#pragma once
#include <string>

using namespace std;


class dependency_to_fake
{
public:
    dependency_to_fake() = default;
    virtual ~dependency_to_fake() = default;

    string get_firstname() const;

    static string get_lastname();

    virtual long calculate(const int value) const;

};

