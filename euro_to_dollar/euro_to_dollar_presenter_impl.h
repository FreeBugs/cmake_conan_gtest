#pragma once
#include "euro_to_dollar_presenter.h"
#include "euro_to_dollar_view.h"

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
		view_->set_euro("0.0");
		view_->set_dollar("0.0");
		view_->set_rechnen_enabled(true);
	}

	void rechnen() const override
	{
		try
		{
			const double euro = std::stod(view_->get_euro());
			const double dollar = model_->convert(euro);
			view_->set_dollar(std::to_string(dollar));
		}
		catch (const std::exception& ex)
		{
			view_->set_dollar(ex.what());
		}
	}

	void beenden() const override
	{
		view_->dispose();
	}

	void update_rechnen_action_state() const override
	{
		try
		{
			std::stod(view_->get_euro());
			view_->set_rechnen_enabled(true);
		}
		catch (const std::exception& ex)
		{
			view_->set_rechnen_enabled(false);
		}
	}
};

