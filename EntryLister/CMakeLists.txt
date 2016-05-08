project(lister)

add_library(lister SHARED EntryLister.cpp EntryLister.h )

target_link_libraries(lister entry)