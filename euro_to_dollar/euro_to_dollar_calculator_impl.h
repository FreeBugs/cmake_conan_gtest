#pragma once
#include "exchange_rate_service.h"
#include "euro_to_dollar_calculator.h"
class euro_to_dollar_calculator_impl :
    public euro_to_dollar_calculator
{
private:
	exchange_rate_service& exchange_rate_service_;
public:
	euro_to_dollar_calculator_impl(exchange_rate_service& exchange_rate_service) :exchange_rate_service_(exchange_rate_service) {};
	[[nodiscard]] double convert(const double dollar) const override
	{
		return dollar * exchange_rate_service_.get_rate_for("USD");
	}
};

