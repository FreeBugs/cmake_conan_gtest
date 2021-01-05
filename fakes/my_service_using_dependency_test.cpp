#include "my_service_using_dependency_test.hpp"


std::string dependency_to_fake::get_firstname() const {
    //return "Max";
    return dependency_to_fake_mock_repo::getInstance().getMock((dependency_to_fake *)this).get_firstname();
}

string dependency_to_fake::get_lastname()
{
    return "Mustermann";
}
long dependency_to_fake::calculate(const int value) const
{
    return value * value;
}

TEST_F(myservice_using_dependency_test, FirstMethod) {
dependency_to_fake_mock dMock;
dependency_to_fake_mock_repo::getInstance().add_mock_to_use(&dMock);
EXPECT_CALL(dMock, get_firstname()).WillOnce(::testing::Return("Peter"));

EXPECT_EQ(object_under_test.first_method_under_test(), "Max Hallo");
EXPECT_TRUE(true);
}