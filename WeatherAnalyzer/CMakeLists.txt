cmake_minimum_required(VERSION 3.7)
project(WeatherAnalyzer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Analyzer.cpp Region.cpp Region.h Day.cpp Day.h Stat.cpp Stat.h Utils.h Station.h Station.cpp Utils.cpp)
add_executable(WeatherAnalyzer ${SOURCE_FILES})