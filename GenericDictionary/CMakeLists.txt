cmake_minimum_required(VERSION 3.7)
project(GenericDictionary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES KeyValue.h Dictionary.h)
add_executable(GenericDictionary main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/DictionaryTester.cpp Testing/KeyValueTester.cpp Testing/testMain.cpp Testing/KeyValueTester.h Testing/DictionaryTester.h)
add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})