cmake_minimum_required(VERSION 3.0)
project(QuantModels)

# Set the path to QuantLib within your project
set(QuantLib_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/QuantLib/build)

# Specify the necessary variables for QuantLib
set(QUANTLIB_INCLUDE_DIRS ${QuantLib_DIR}/..)
set(QUANTLIB_LIBRARIES ${QuantLib_DIR}/ql/libQuantLib.so)

add_executable(QuantModels src/main.cpp)
target_include_directories(QuantModels PRIVATE ${QUANTLIB_INCLUDE_DIRS})
target_link_libraries(QuantModels PRIVATE ${QUANTLIB_LIBRARIES})
