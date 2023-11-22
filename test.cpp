#include "RawInput.cpp"
#include "gtest/gtest.h"
#include <fstream>

TEST(AskPreferenceTests, testingYesNoYes) {//should pass, but testing failing values
    ifstream ifs;
    ifs.open("googleTest.txt", )
    RawInput *aRawInput = new RawInput();
    int area = aRawInput->askPreferences();
    EXPECT_FALSE (area == 13);
}