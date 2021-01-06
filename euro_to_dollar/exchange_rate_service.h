#pragma once
#include <string>

class exchange_rate_service
{
public:
	virtual ~exchange_rate_service() = default;
	[[nodiscard]] virtual double get_rate_for(const std::string currency) const = 0;
};

