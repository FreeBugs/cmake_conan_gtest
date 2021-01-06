#pragma once
#include "exchange_rate_service.h"
class exchange_rate_service_impl :
    public exchange_rate_service
{
public:
	[[nodiscard]]  double get_rate_for(const std::string currency) const override
	{
		return 1.1;
	}
};

