#include "euro_to_dollar_application_test.h"



TEST_F(EuroToDollarCalculatorApplicationTest, GetSetEuro)
{
  

   
    objectUnderTest.set_euro("20");
   
    EXPECT_EQ(objectUnderTest.get_euro(), "20");
  

}

TEST_F(EuroToDollarCalculatorApplicationTest, GetSetDollar)
{
  
   
    objectUnderTest.set_dollar("20");
   
    EXPECT_EQ(objectUnderTest.get_dollar(), "20");
  

}

TEST_F(EuroToDollarCalculatorApplicationTest, GetSetRechnenState)
{


    objectUnderTest.set_rechnen_enabled(true);

    EXPECT_EQ(objectUnderTest.is_rechnen_enabled(), true);
    

}



TEST_F(EuroToDollarCalculatorApplicationTest, RechnenButtonClick) {

    ui_.btn_rechnen->setEnabled(true);

    EXPECT_CALL(p,rechnen()).Times(1);
   
    QSignalSpy rechnenSpy(ui_.btn_rechnen, SIGNAL(clicked()));

    // objectUnderTest.ui.btn_rechnen->animateClick();

    QTest::mouseClick(ui_.btn_rechnen, Qt::LeftButton);
    

    EXPECT_EQ(rechnenSpy.count(), 1);
   

}

TEST_F(EuroToDollarCalculatorApplicationTest, BeendenButtonClick) {

    

    EXPECT_CALL(p, beenden()).Times(1);

    QSignalSpy rechnenSpy(ui_.btn_beenden, SIGNAL(clicked()));

    

    QTest::mouseClick(ui_.btn_beenden, Qt::LeftButton);


    EXPECT_EQ(rechnenSpy.count(), 1);
  

}

TEST_F(EuroToDollarCalculatorApplicationTest, EuroTextChanged) {



    EXPECT_CALL(p, update_rechnen_action_state()).Times(1);

    QSignalSpy textChangedSpy(ui_.txt_euro, SIGNAL(textChanged(const QString&)));



   
    QTest::keyClick(ui_.txt_euro,'a');

    EXPECT_EQ(textChangedSpy.count(), 1);
   

}
