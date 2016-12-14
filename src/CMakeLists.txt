set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(bubblesort bubbleSort.cpp)
add_executable(bubbleSort main.cpp)
target_link_libraries (bubbleSort bubblesort)
