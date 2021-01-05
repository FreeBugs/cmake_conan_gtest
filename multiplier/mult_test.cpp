#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "multiplizierer.hpp"
#include "multiplizierer_optimierer.hpp"

using namespace testing;

class MultMock : public multiplizierer {
public:
    MOCK_METHOD(long, mult, (int a, int b), (override));
};

class MultTest : public Test {
public:
    MultMock mult_mock;
    multiplizierer_optimierer objectUnderTest{mult_mock};
};

TEST_F(MultTest, a_is_greater_than_b_not_swapped) {
    EXPECT_CALL(mult_mock, mult(1, 100)).WillOnce(Return(100));
    objectUnderTest.mult(100, 1);
}

TEST_F(MultTest, a_is_smaller_than_b_swapped) {
    EXPECT_CALL(mult_mock, mult(1, 100)).WillOnce(Return(100));
    objectUnderTest.mult(1, 100);
}