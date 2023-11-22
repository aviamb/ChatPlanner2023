#include "RawInput.cpp"
#include "gtest/gtest.h"


TEST(AskPreferenceTests, testingYesNoYes) {//should pass, but testing failing values
    ifstream ifs;
    ifs.open()
    RawInput *aRawInput = new RawInput();
    int area = aRawInput->askPreferences();
    EXPECT_FALSE (area == 13);
}