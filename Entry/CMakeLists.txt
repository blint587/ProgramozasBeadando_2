project(entry)

add_library(entry SHARED Entry.cpp Entry.h)

target_link_libraries(entry datetime)