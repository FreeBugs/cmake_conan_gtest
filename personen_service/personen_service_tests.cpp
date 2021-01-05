#include "gtest/gtest.h"
#include "person.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "person_repository.h"
#include "person_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"

using namespace testing;

ACTION(ThrowRuntimeError)
{
    throw std::runtime_error("foo");
}

ACTION(ThrowRepositoryException)
{
    throw repository_exception();
}

class mock_person_repository : public person_repository {
public:
    MOCK_METHOD(void, save, (person), (override));
    MOCK_METHOD(void, update, (person), (override));
    MOCK_METHOD(void, remove, (person), (override));
    MOCK_METHOD(std::vector<person>, find_all, (), (const, override));
    MOCK_METHOD(std::optional<person>, find_by_id, (std::string id), (const, override));
};

class person_service_impl_test : public Test {
public:
    person good_person{"1", "good", "name"};
    mock_person_repository person_repo;
    person_service_impl objectUnderTest{person_repo};
};

class person_service_impl_parametrized_test : public TestWithParam<person> {
public:
    mock_person_repository person_repo;
    person_service_impl objectUnderTest{person_repo};
};

TEST_F(person_service_impl_test, a_valid_name_is_fine) {
    EXPECT_CALL(person_repo, find_by_id).WillOnce(ThrowRepositoryException());
    EXPECT_CALL(person_repo, save).Times(1);
    objectUnderTest.speichern(good_person);
}

TEST_F(person_service_impl_test, a_valid_name_as_strings_is_fine) {
    EXPECT_CALL(person_repo, find_by_id).WillOnce(ThrowRepositoryException());
    person saved_p;
    EXPECT_CALL(person_repo, save).WillOnce(SaveArg<0>(&saved_p));
    objectUnderTest.speichern(good_person.GetVorname(),
                              good_person.GetNachname());
    EXPECT_EQ(good_person.GetVorname(), saved_p.GetVorname());
    EXPECT_EQ(good_person.GetNachname(), saved_p.GetNachname());
}

TEST_F(person_service_impl_test, a_valid_name_is_fine_for_updating_a_record) {
    EXPECT_CALL(person_repo, find_by_id).WillOnce(Return(good_person));
    EXPECT_CALL(person_repo, update).Times(1);
    objectUnderTest.speichern(good_person);
}

TEST_P(person_service_impl_parametrized_test, invalid_names_fail) {
    EXPECT_CALL(person_repo, save).Times(0);
    EXPECT_THROW({
    auto p = GetParam();
    objectUnderTest.speichern(p);}, personen_service_exception);
}

INSTANTIATE_TEST_SUITE_P(
        PersonParametrizedTests,
        person_service_impl_parametrized_test,
        ::testing::Values(
                person{"1", "a", "aaa"},
                person{"1", "aaa", "a"},
                person{"1", "Atilla", "foobar"}
        ));


TEST_F(person_service_impl_test, system_error_from_underlying_component) {
    EXPECT_CALL(person_repo, save).WillOnce(ThrowRuntimeError());
    EXPECT_THROW(objectUnderTest.speichern(good_person), std::runtime_error);
}

TEST_F(person_service_impl_test, repo_error_from_underlying_component) {
    EXPECT_CALL(person_repo, save).WillOnce(ThrowRepositoryException());
    EXPECT_THROW(objectUnderTest.speichern(good_person), personen_service_exception);
}