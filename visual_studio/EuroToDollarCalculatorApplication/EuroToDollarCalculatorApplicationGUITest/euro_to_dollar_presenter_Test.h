#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../EuroToDollarCalculatorApplication/euro_to_dollar_presenter_impl.h"
#include <regex>

using namespace ::testing;

class Mockeuro_to_dollar_calculator : public euro_to_dollar_calculator {
public:
	MOCK_METHOD(double, convert, (const double dollar), (const, override));
};

class euro_to_dollar_view_mock : public euro_to_dollar_view
{
public:
	MOCK_METHOD(void, set_presenter, (euro_to_dollar_presenter* presenter), (override));
	MOCK_METHOD(void, dispose, (), (override));
	MOCK_METHOD(std::string, get_euro, (), (const, override));
	MOCK_METHOD(void, set_euro, (std::string euro), (override));
	MOCK_METHOD(std::string, get_dollar, (), (const, override));
	MOCK_METHOD(void, set_dollar, (std::string dollar), (override));
	MOCK_METHOD(bool, is_rechnen_enabled, (), (const, override));
	MOCK_METHOD(void, set_rechnen_enabled, (bool enabled), (override));
};

class euro_to_dollar_presenter_Test : public Test
{
protected:
	NiceMock<euro_to_dollar_view_mock> view_mock;
	Mockeuro_to_dollar_calculator calculator_mock;
	euro_to_dollar_presenter_impl objectUnderTest;

	void SetUp() override
	{
		objectUnderTest.set_view(&view_mock);
		objectUnderTest.set_model(&calculator_mock);
	}
};

TEST_F(euro_to_dollar_presenter_Test, populate_items_sets_view_values_to_zero)
{
	EXPECT_CALL(view_mock, set_euro("0.00")).Times(1).WillOnce(DoDefault());
	EXPECT_CALL(view_mock, set_dollar("0.00")).Times(1);
	EXPECT_CALL(view_mock, set_rechnen_enabled(true)).Times(1);

	objectUnderTest.populate_items();
}

TEST_F(euro_to_dollar_presenter_Test, rechnen_get_euro_is_called)
{
	EXPECT_CALL(view_mock, get_euro()).WillOnce(Return("1.0"));

	objectUnderTest.rechnen();
}

TEST_F(euro_to_dollar_presenter_Test, rechnen_get_euro_if_invalid_then_error_is_set_to_dollar)
{
	ON_CALL(view_mock, get_euro()).WillByDefault(Return("Test"));

	std::string dollar_string;
	EXPECT_CALL(view_mock, set_dollar(_)).WillOnce(SaveArg<0>(&dollar_string));

	objectUnderTest.rechnen();

	EXPECT_EQ(dollar_string, "Not a number");
}


MATCHER_P(RegexMatch, regex, "perfect RegexMatcher")
{
	std::regex re(regex);
	std::smatch m;
	return std::regex_match(arg, m, re);
}

TEST_F(euro_to_dollar_presenter_Test, rechnen_get_euro_if_valid_set_dollar_is_called)
{
	ON_CALL(view_mock, get_euro()).WillByDefault(Return("1.0"));

	EXPECT_CALL(view_mock, set_dollar(RegexMatch("[0-9]+\\.[0-9][0-9]"))).Times(1);

	objectUnderTest.rechnen();
}

TEST_F(euro_to_dollar_presenter_Test, rechnen_calculate_exception_is_set_to_dollar_field)
{
	ON_CALL(view_mock, get_euro()).WillByDefault(Return("1.0"));

	std::string error_msg("No Exchange rate");
	EXPECT_CALL(calculator_mock, convert(_)).WillOnce(Throw(std::runtime_error(error_msg)));

	EXPECT_CALL(view_mock, set_dollar(error_msg));

	objectUnderTest.rechnen();
}

TEST_F(euro_to_dollar_presenter_Test, rechnen_calculate_is_called_with_euro_value_in_double)
{
	ON_CALL(view_mock, get_euro()).WillByDefault(Return("5.0"));

	EXPECT_CALL(calculator_mock, convert(5.0));

	objectUnderTest.rechnen();
}

TEST_F(euro_to_dollar_presenter_Test, rechnen_set_dollar_is_called_with_converted_value)
{
	ON_CALL(view_mock, get_euro()).WillByDefault(Return("25.0"));

	EXPECT_CALL(calculator_mock, convert(25.0)).WillOnce(Return(99));
	EXPECT_CALL(view_mock, set_dollar("99.00"));

	objectUnderTest.rechnen();
}

TEST_F(euro_to_dollar_presenter_Test, beenden_calls_dispose_on_view)
{
	EXPECT_CALL(view_mock, dispose());

	objectUnderTest.beenden();
}

TEST_F(euro_to_dollar_presenter_Test, update_rechnen_action_state_sets_rechnen_enabled_false_on_invalid_number)
{
	ON_CALL(view_mock, get_euro()).WillByDefault(Return("5,Test"));

	EXPECT_CALL(view_mock, set_rechnen_enabled(false));

	objectUnderTest.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_Test, update_rechnen_action_state_sets_rechnen_enabled_true_on_valid_number)
{
	EXPECT_CALL(view_mock, get_euro()).WillOnce(Return("Test")).WillOnce(Return("5.0"));
	bool rechnen_enabled = true; // see euro_to_dollar_presenter_Test.populate_items_sets_view_values_to_zero
	ON_CALL(view_mock, set_rechnen_enabled(_)).WillByDefault(SaveArg<0>(&rechnen_enabled));

	objectUnderTest.update_rechnen_action_state();
	objectUnderTest.update_rechnen_action_state();

	EXPECT_TRUE(rechnen_enabled);
}