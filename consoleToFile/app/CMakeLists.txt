include_directories(${CMAKE_SOURCE_DIR}/lib)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

set(src main.cpp)

add_executable(myApp ${src})

target_link_libraries(myApp consoleToFile)

install(TARGETS myApp DESTINATION bin)
