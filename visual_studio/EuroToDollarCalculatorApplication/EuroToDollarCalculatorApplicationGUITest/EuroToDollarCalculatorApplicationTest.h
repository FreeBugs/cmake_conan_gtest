#pragma once


#include <QtTest>
#include <QCoreApplication>

#include "..\EuroToDollarCalculatorApplication\EuroToDollarCalculatorApplication.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Mockeuro_to_dollar_presenter.h"

using namespace ::testing;




class EuroToDollarCalculatorApplicationTest : public Test
{
    
protected:
    int i = 0;
    QApplication app{ i, nullptr };
    Mockeuro_to_dollar_presenter p;
    EuroToDollarCalculatorApplication objectUnderTest;
    Ui::EuroToDollarCalculatorApplicationClass ui_ = objectUnderTest.ui;
	
	void SetUp() override
	{
        objectUnderTest.set_presenter(&p);
	}

};

