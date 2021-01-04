#include "gtest/gtest.h"
#include "schwein.hpp"
#include "gtest/gtest.h"

using namespace testing;
using namespace tiere;

class PigTest : public Test {
public:
    PigTest() {}

//    void SetUp(const std::string name) {
//        objectUnderTest = schwein(name);
//    }

    schwein objectUnderTest;
};

TEST_F(PigTest, pig_start_weight_is_10) {
    EXPECT_EQ(objectUnderTest.get_gewicht(), 10);
}

TEST_F(PigTest, pig_throws_if_constructed_as_elsa) {
    EXPECT_THROW(
            schwein objectUnderTest("Elsa"), std::invalid_argument);
}

TEST_F(PigTest, pig_likes_other_names) {
    EXPECT_NO_THROW(schwein objectUnderTest("Horst"));
}

TEST_F(PigTest, pig_throws_if_setname_with_elsa) {
    EXPECT_THROW(
            objectUnderTest.set_name("Elsa"), std::invalid_argument);
}

TEST_F(PigTest, pig_likes_to_get_names_set_with_other_names) {
    EXPECT_NO_THROW(objectUnderTest.set_name("Horst"));
}

TEST_F(PigTest, pig_is_fatter_after_eating) {
    EXPECT_NO_THROW(objectUnderTest.fressen());
    EXPECT_EQ(objectUnderTest.get_gewicht(), 11);
}

TEST_F(PigTest, pig_ostream_returns_the_name_and_weight) {
    EXPECT_NO_THROW(objectUnderTest.set_name("Rüdiger"));
    std::stringstream pig_stream;
    pig_stream << objectUnderTest;
    EXPECT_EQ(pig_stream.str(), "Schwein: Name=Rüdiger, Gewicht=10");
}