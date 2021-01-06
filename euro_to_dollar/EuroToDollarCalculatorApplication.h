#pragma once
#include "euro_to_dollar_view.h"
#include "euro_to_dollar_presenter.h"
#include <QtWidgets/QMainWindow>
#include "ui_EuroToDollarCalculatorApplication.h"

class EuroToDollarCalculatorApplication : public QMainWindow, public euro_to_dollar_view
{
	Q_OBJECT

friend class EuroToDollarCalculatorApplicationTest;

private:
	euro_to_dollar_presenter* presenter_{nullptr};

public:
    EuroToDollarCalculatorApplication(QWidget *parent = Q_NULLPTR);

	void set_presenter(euro_to_dollar_presenter* presenter) override
	{
		presenter_ = presenter;
	}
	
	void set_euro(std::string euro) override
	{
		ui.txt_euro->setText(euro.c_str());
	}

	[[nodiscard]] std::string get_euro() const override
	{
		return ui.txt_euro->text().toStdString();
	}
	void set_dollar(std::string dollar) override
	{
		ui.txt_dollar->setText(dollar.c_str());
	}

	[[nodiscard]] std::string get_dollar() const override
	{
		return ui.txt_dollar->text().toStdString();
	}

	void set_rechnen_enabled(bool state) override
	{
		ui.btn_rechnen->setEnabled(state);
	}

	[[nodiscard]] bool is_rechnen_enabled() const override
    {
	    return ui.btn_rechnen->isEnabled();
    }

	void dispose() override
	{
		close();
	}


private slots:
	void on_btn_rechnen_clicked() {
		presenter_->rechnen();
	}
	void on_btn_beenden_clicked() {
		presenter_->beenden();
	}

	void on_txt_euro_textChanged(const QString& text)
	{
		presenter_->update_rechnen_action_state();
	}
	



private:
    Ui::EuroToDollarCalculatorApplicationClass ui;
};
