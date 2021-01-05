#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <deque>
#include <map>
#include "my_service_using_dependency.hpp"

class dependency_to_fake_mock
{
public:
    MOCK_METHOD(std::string, get_firstname,());
    MOCK_METHOD(std::string, get_lastname, ());
    MOCK_METHOD(long, calculate, (const int));
};

class dependency_to_fake_mock_repo
{
public:
    ~dependency_to_fake_mock_repo() = default;
    void add_mock_to_use(dependency_to_fake_mock* dependency_to_fake_mock_) { free_mock_.push_back(dependency_to_fake_mock_); }


    dependency_to_fake_mock& getMock(dependency_to_fake* original)
    {
        // TODO: use more sophisticated way to add mock to map...
        if (! used_mock_[original])
        {
            used_mock_[original] = free_mock_.front();
            free_mock_.pop_front();
        }
        return *used_mock_[original];
    }
    static dependency_to_fake_mock_repo& getInstance() {
        static dependency_to_fake_mock_repo instance;
        return instance;
    }

private:
    dependency_to_fake_mock_repo() = default;

    std::map<dependency_to_fake*, dependency_to_fake_mock*> used_mock_;
    std::deque<dependency_to_fake_mock*> free_mock_;
};


class myservice_using_dependency_test:public ::testing::Test
{
protected:
    my_service_using_dependency object_under_test;
};