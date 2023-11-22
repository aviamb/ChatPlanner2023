CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(finalProject)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    test.cpp
    Schedule.cpp
    Event.cpp
    RawInput.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)
