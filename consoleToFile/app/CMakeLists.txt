include_directories(${CMAKE_SOURCE_DIR}/lib)

set(src main.cpp)

add_executable(myApp ${src})

target_link_libraries(myApp fromRomanNumerals)

install(TARGETS myApp DESTINATION bin)
