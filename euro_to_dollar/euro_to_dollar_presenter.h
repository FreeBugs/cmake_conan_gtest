#pragma once
#include "euro_to_dollar_calculator.h"

class euro_to_dollar_view;

class euro_to_dollar_presenter
{
public:
	virtual ~euro_to_dollar_presenter() = default;
	
	

	virtual void set_view(euro_to_dollar_view *view) = 0;
	virtual void set_model(euro_to_dollar_calculator *model) = 0;
	virtual void rechnen()  const = 0;
	virtual void beenden()  const = 0;
	virtual void populate_items()  const = 0; 
	virtual void update_rechnen_action_state() const = 0; // Nicht beachten
};

