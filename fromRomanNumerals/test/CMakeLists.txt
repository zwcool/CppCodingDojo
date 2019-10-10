#include_directories(${CMAKE_SOURCE_DIR}/lib)

set(src main.cpp
		fromRomanNumeralsTest.cpp
		catch.hpp)

add_executable(testFromRomanNumerals ${src})

#target_link_libraries(testFromRomanNumerals fromRomanNumerals)

install(TARGETS testFromRomanNumerals DESTINATION bin)