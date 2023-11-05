
file(GLOB smd-srcs 
    *.c *.h)

add_library(smd STATIC ${smd-srcs})

if (WIN32)
    target_compile_definitions(smd PUBLIC SMD_PLATFORM_WINDOWS=1)
    target_link_libraries(smd PRIVATE Shlwapi)
endif()
if (APPLE)
    target_compile_definitions(smd PUBLIC SMD_PLATFORM_MACOS=1)
endif()

target_compile_definitions(smd PRIVATE SMD_IMPLEMENTATION=1)
target_include_directories(smd PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR})
