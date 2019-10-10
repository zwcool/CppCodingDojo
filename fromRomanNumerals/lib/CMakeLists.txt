set(src fromRomanNumerals.cpp)
set(include fromRomanNumerals.h)

add_library(fromRomanNumerals SHARED ${include} ${src})

install(TARGETS fromRomanNumerals DESTINATION lib)
