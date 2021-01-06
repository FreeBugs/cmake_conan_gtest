#include "EuroToDollarCalculatorApplication.h"
#include <QtWidgets/QApplication>
#include "exchange_rate_service_impl.h"
#include "euro_to_dollar_calculator_impl.h"
#include "euro_to_dollar_presenter_impl.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EuroToDollarCalculatorApplication w;

    exchange_rate_service_impl exchange_rate_service;
    euro_to_dollar_calculator_impl euro_to_dollar_calculator{ exchange_rate_service };
    euro_to_dollar_presenter_impl presenter;
    w.set_presenter(&presenter);
    presenter.set_model(&euro_to_dollar_calculator);
    presenter.set_view(&w);
	
    w.show();
    return a.exec();
}
