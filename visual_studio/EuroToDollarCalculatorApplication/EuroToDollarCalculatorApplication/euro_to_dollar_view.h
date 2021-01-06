#pragma once
#include <string>

class euro_to_dollar_presenter;
class euro_to_dollar_view
{
public:
	virtual ~euro_to_dollar_view() = default;
	virtual void set_presenter(euro_to_dollar_presenter* presenter) = 0;
	
	
	virtual  void dispose() = 0;

	[[nodiscard]] virtual std::string get_euro() const = 0;
	
	virtual void set_euro(std::string euro) = 0;
	
	[[nodiscard]] virtual std::string  get_dollar() const = 0;
	
	virtual void set_dollar(std::string dollar) = 0;
	
	[[nodiscard]] virtual bool is_rechnen_enabled() const = 0;
	
	virtual void set_rechnen_enabled(bool enabled) = 0;
};

