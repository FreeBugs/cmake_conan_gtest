#pragma once
class euro_to_dollar_calculator
{
public:
	virtual ~euro_to_dollar_calculator() = default;
	[[nodiscard]] virtual double convert(const double dollar) const = 0;
};

