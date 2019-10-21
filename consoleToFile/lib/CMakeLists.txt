set(src consoleToFile.cpp)
set(include consoleToFile.h)

add_library(consoleToFile SHARED ${include} ${src})

install(TARGETS consoleToFile DESTINATION lib)
