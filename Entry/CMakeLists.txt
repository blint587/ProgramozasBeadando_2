project(entry)

add_library(entry SHARED Entry.cpp Entry.h ../BaseClass.h ../BaseClass.cpp)

target_link_libraries(entry datetime)