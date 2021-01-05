#include "gtest/gtest.h"
#include "person.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "person_repository.h"
#include "person_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"
#include "fancy_throw_asserts.hpp"

using namespace testing;



ACTION(ThrowRuntimeError) {
    throw std::runtime_error("foo");
}

ACTION(ThrowRepositoryException) {
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

class mock_antipath_checker : public antipath_checker {
public:
    MOCK_METHOD(bool, is_antipath, (std::string), (override));
};

class person_service_impl_test : public Test {
public:
    person good_person{"1", "good", "name"};
    mock_person_repository person_repo;
    mock_antipath_checker antipath_checker;
    person_service_impl objectUnderTest{person_repo, antipath_checker};
};

class person_service_impl_parametrized_test : public TestWithParam<person> {
public:
    mock_person_repository person_repo;
    mock_antipath_checker antipath_checker;
    person_service_impl objectUnderTest{person_repo, antipath_checker};
};

TEST_F(person_service_impl_test, a_valid_name_is_fine) {
    {
        InSequence seq;
        EXPECT_CALL(antipath_checker, is_antipath).WillOnce(Return(false));
        EXPECT_CALL(person_repo, save).Times(1);
    }
    EXPECT_CALL(person_repo, find_by_id).WillOnce(ThrowRepositoryException());
    objectUnderTest.speichern(good_person);
}

TEST_F(person_service_impl_test, antipath_is_rejected) {
    EXPECT_CALL(antipath_checker, is_antipath).WillOnce(Return(true));
    // EXPECT_THROW(objectUnderTest.speichern(good_person), personen_service_exception);
    ASSERT_EXCEPTION({ objectUnderTest.speichern(good_person); }, personen_service_exception, "WTF Vorname");
}

TEST_F(person_service_impl_test, a_valid_name_as_strings_is_fine) {
    EXPECT_CALL(antipath_checker, is_antipath).WillOnce(Return(false));
    EXPECT_CALL(person_repo, find_by_id).WillOnce(ThrowRepositoryException());
    person saved_p;
    EXPECT_CALL(person_repo, save).WillOnce(SaveArg<0>(&saved_p));
    objectUnderTest.speichern(good_person.GetVorname(),
                              good_person.GetNachname());
    EXPECT_EQ(good_person.GetVorname(), saved_p.GetVorname());
    EXPECT_EQ(good_person.GetNachname(), saved_p.GetNachname());
}

TEST_F(person_service_impl_test, a_valid_name_is_fine_for_updating_a_record) {
    EXPECT_CALL(antipath_checker, is_antipath).WillOnce(Return(false));
    EXPECT_CALL(person_repo, find_by_id).WillOnce(Return(good_person));
    EXPECT_CALL(person_repo, update).Times(1);
    objectUnderTest.speichern(good_person);
}

TEST_P(person_service_impl_parametrized_test, short_vorname_or_nachname_fails) {
    EXPECT_CALL(person_repo, save).Times(0);
    ASSERT_EXCEPTION_REGEX({
                     auto p = GetParam();
                     objectUnderTest.speichern(p);
                 }, personen_service_exception, ".*zu kurz.*");
}

INSTANTIATE_TEST_SUITE_P(
        PersonParametrizedTests,
        person_service_impl_parametrized_test,
        ::testing::Values(
                person{"1", "a", "aaa"},
                person{"1", "aaa", "a"}
        ));


TEST_F(person_service_impl_test, system_error_from_underlying_component) {
    EXPECT_CALL(person_repo, find_by_id).WillOnce(ThrowRepositoryException());
    EXPECT_CALL(antipath_checker, is_antipath).WillOnce(Return(false));
    EXPECT_CALL(person_repo, save).WillOnce(ThrowRuntimeError());
    EXPECT_THROW(objectUnderTest.speichern(good_person), std::runtime_error);
}

TEST_F(person_service_impl_test, repo_error_from_underlying_component) {
    EXPECT_CALL(person_repo, find_by_id).WillOnce(ThrowRepositoryException());
    EXPECT_CALL(antipath_checker, is_antipath).WillOnce(Return(false));
    EXPECT_CALL(person_repo, save).WillOnce(ThrowRepositoryException());
    EXPECT_THROW(objectUnderTest.speichern(good_person), personen_service_exception);
}

