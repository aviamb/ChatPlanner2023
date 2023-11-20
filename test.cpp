#include "gtest/gtest.h"
#include "Event.h"
#include "Schedule.h"
#include "RawInput.h"

TEST(EventTests,TestTakenConstructor){
    Taken t;
    EXPECT_EQ(t.getName(), "");
    EXPECT_EQ(t.getDescription(), "");
}
TEST(EventTests,TestLeisureConstructor){
    Leisure l("go for a swim","at the gym");
    EXPECT_EQ(l.getName(), "go for a swim");
    EXPECT_EQ(l.getDescription(), "at the gym");

}
TEST(EventTests,TestWorkConstructor){
    Work w("do hw",2,"at the library");
    EXPECT_EQ(w.getName(), "do hw");
    EXPECT_EQ(w.getDescription(), "at the library");
}
// TEST(MainTests, TestCallOrder1){
//     Schedule s;
// }

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
