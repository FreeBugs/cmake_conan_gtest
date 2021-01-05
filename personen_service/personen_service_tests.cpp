#include "gtest/gtest.h"
#include "person.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "person_repository.h"
#include "person_service_impl.h"

using namespace testing;

class mock_person_repository : public person_repository {
public:
    MOCK_METHOD(void, save, (person), (override));
    MOCK_METHOD(void, update, (person), (override));
    MOCK_METHOD(void, remove, (person), (override));
    MOCK_METHOD(std::vector<person>, find_all, (), (const, override));
    MOCK_METHOD(person, find_by_id, (std::string id), (const, override));
};

class PersonTest : public Test {
public:
    mock_person_repository person_repo;
    person_service_impl objectUnderTest{person_repo};
};

TEST_F(PersonTest, a_valid_name_is_fine) {
    EXPECT_CALL(person_repo, save).Times(1);
    person p;
    p.SetNachname("abc");
    p.SetVorname("abc");
    p.SetId("abc");
    objectUnderTest.speichern(p);
}