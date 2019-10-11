set(src filePathHelper.cpp)
set(include filePathHelper.h)

add_library(filePathHelper SHARED ${include} ${src})

install(TARGETS filePathHelper DESTINATION lib)
