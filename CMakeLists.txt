CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    test.cpp
    Schedule.cpp
    Event.cpp
    RawInput.cpp
)

ADD_EXECUTABLE(runProgram
    main.cpp
    Schedule.cpp
    Event.cpp
    RawInput.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
