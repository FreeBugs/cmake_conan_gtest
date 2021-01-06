#pragma once
#include "euro_to_dollar_presenter.h"
#include "euro_to_dollar_view.h"
#include <stdexcept>
#include  <iomanip>
#include <sstream>

class euro_to_dollar_presenter_impl :
    public euro_to_dollar_presenter
{
private:
	euro_to_dollar_view* view_{nullptr};
	euro_to_dollar_calculator* model_{ nullptr };
public:
	euro_to_dollar_presenter_impl() = default;

	void set_model(euro_to_dollar_calculator* model) override
	{
		model_ = model;
	}

	void set_view(euro_to_dollar_view* view) override
	{
		view_ = view;
		populate_items();
	}

	void populate_items() const override
	{
		view_->set_dollar("0.00");
		view_->set_euro("0.00");
		view_->set_rechnen_enabled(true);
	}

	void rechnen() const override
	{
		try
		{
			euro_to_dollar_conversion();
		}
		catch (std::invalid_argument& e)
		{
			view_->set_dollar("Not a number");
		}
		catch (std::exception& e)
		{
			view_->set_dollar(e.what());
		}
	}

	double get_euros() const
	{
		std::string euros = view_->get_euro();
		size_t process_count;
		double eurosd = std::stod(euros, &process_count);
		if (process_count != euros.size())
		{
			throw std::invalid_argument("processed size does not match input");
		}
		return eurosd;
	}

	void euro_to_dollar_conversion() const
	{
		double eurosd = get_euros();
		double dollars_in_d = model_->convert(eurosd);
		std::stringstream sstream;
		sstream << std::setprecision(2) << std::fixed << dollars_in_d;
		view_->set_dollar(sstream.str());
	}

	void beenden() const override
	{
		view_->dispose();
	}

	void update_rechnen_action_state() const override
	{
		try {
			get_euros();
			view_->set_rechnen_enabled(true);
		}
		catch (std::invalid_argument& e)
		{
			view_->set_rechnen_enabled(false);
		}
	}
};

