cmake_minimum_required(VERSION 3.10)
project(cmake-build-debug/EsameTema3)  # Deve corrispondere al nome della tua cartella progetto

set(CMAKE_CXX_STANDARD 20)

#configurazione per ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

#programma
add_executable(EsameTema3
        main.cpp
        Activity.cpp Activity.h
        Day.cpp Day.h
        View.cpp View.h
        isValidString.h
        isValidTime.h
)

target_link_libraries(EsameTema3 ${CURSES_LIBRARIES})

#setup per GTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#test: Activity
add_executable(test_activity
        test_activity.cpp
        Activity.cpp
)
target_link_libraries(test_activity
        GTest::GTest
        GTest::Main
        pthread
)
add_test(NAME cmake-build-debug/test_activity COMMAND cmake-build-debug/test_activity)

#test: Day
add_executable(test_day
        test_day.cpp
        Activity.cpp
        Day.cpp
)
target_link_libraries(test_day
        GTest::GTest
        GTest::Main
        pthread
)
add_test(NAME test_day COMMAND test_day)
