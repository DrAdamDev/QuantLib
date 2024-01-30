cmake_minimum_required(VERSION 3.0)
project(QuantLibExamples)

# Set the path to QuantLib within your project
set(QuantLib_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/QuantLib/build)

# Specify the necessary variables for QuantLib
set(QUANTLIB_INCLUDE_DIRS ${QuantLib_DIR};${CMAKE_CURRENT_SOURCE_DIR}/lib/QuantLib)
set(QUANTLIB_LIBRARIES ${QuantLib_DIR}/ql/libQuantLib.so.1)

add_executable(ExampleModels src/main.cpp)
target_include_directories(ExampleModels PRIVATE ${QUANTLIB_INCLUDE_DIRS})
target_link_libraries(ExampleModels PRIVATE ${QUANTLIB_LIBRARIES})
