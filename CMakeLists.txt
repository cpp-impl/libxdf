# ! https://cmake.org/cmake/help/book/mastering-cmake/cmake/Help/guide/tutorial/index.html#id1
# ! Source - https://stackoverflow.com/a/33090791
# ! Posted by Arne, modified by community. See post 'Timeline' for change history
# ! Retrieved 2026-09-12, License - CC BY-SA 4.0

cmake_minimum_required(VERSION 3.28)

project(libxdf VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(xdf_core 
    src/main/lib.cpp
)

target_include_directories(xdf_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} 
    src/main/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE xdf_core)

set(STRICT_WARNINGS "")
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    list(APPEND STRICT_WARNINGS /W4 /WX /permissive-)
else()
    list(APPEND STRICT_WARNINGS -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Werror)
endif()

target_compile_options(xdf_core PRIVATE ${STRICT_WARNINGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${STRICT_WARNINGS})

# ! TESTING
enable_testing()

add_executable(xdf_test 
    src/test/test_main.cpp
)

target_link_libraries(xdf_test PRIVATE xdf_core)
target_compile_options(xdf_test PRIVATE ${STRICT_WARNINGS})

add_test(NAME CoreLibraryTest COMMAND xdf_test)


# add_executable(${PROJECT_NAME}
#     src/main/main.cpp
#     src/main/lib.cpp
#     # src/other_module.cpp
# )


###############################################################################
## file globbing ##############################################################
###############################################################################

# # these instructions search the directory tree when CMake is
# # invoked and put all files that match the pattern in the variables
# # `sources` and `data`
# file(GLOB_RECURSE sources      src/main/*.cpp src/main/*.h)
# file(GLOB_RECURSE sources_test src/test/*.cpp)
# file(GLOB_RECURSE data resources/*)
# # you can use set(sources src/main.cpp) etc if you don't want to
# # use globbing to find files automatically

###############################################################################
## target definitions #########################################################
###############################################################################

# # add the data to the target, so it becomes visible in some IDE
# add_executable(example ${sources} ${data})

# # just for example add some compiler flags
# target_compile_options(example PUBLIC -std=c++26 -Wall -Wfloat-conversion)

# # this lets me include files relative to the root source directory with a <> pair
# target_include_directories(example PUBLIC src/main)

# # this copies all resource files in the build directory
# # we need this, because we want to work with paths relative to the executable
# file(COPY ${data} DESTINATION resources)

###############################################################################
## dependencies ###############################################################
###############################################################################

# # this defines the variables Boost_LIBRARIES that contain all library names
# # that we need to link to
# find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)

# target_link_libraries(example PUBLIC
#   ${Boost_LIBRARIES}
#   # here you can add any library dependencies
# )

###############################################################################
## testing ####################################################################
###############################################################################

# # this is for our testing framework
# # we don't add REQUIRED because it's just for testing
# find_package(GTest)

# if(GTEST_FOUND)
#   add_executable(unit_tests ${sources_test} ${sources})

#   # we add this define to prevent collision with the main
#   # this might be better solved by not adding the source with the main to the
#   # testing target
#   target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

#   # this allows us to use our executable as a link library
#   # therefore we can inherit all compiler options and library dependencies
#   set_target_properties(example PROPERTIES ENABLE_EXPORTS on)

#   target_link_libraries(unit_tests PUBLIC
#     ${GTEST_BOTH_LIBRARIES}
#     example
#   )

#   target_include_directories(unit_tests PUBLIC
#     ${GTEST_INCLUDE_DIRS} # doesn't do anything on Linux
#   )
# endif()

###############################################################################
## packaging ##################################################################
###############################################################################

# # all install commands get the same destination. this allows us to use paths
# # relative to the executable.
# install(TARGETS example DESTINATION example_destination)
# # this is basically a repeat of the file copy instruction that copies the
# # resources in the build directory, but here we tell CMake that we want it
# # in the package
# install(DIRECTORY resources DESTINATION example_destination)

# # now comes everything we need, to create a package
# # there are a lot more variables you can set, and some
# # you need to set for some package types, but we want to
# # be minimal here
# set(CPACK_PACKAGE_NAME "MyExample")
# set(CPACK_PACKAGE_VERSION "1.0.0")

# # we don't want to split our program up into several things
# set(CPACK_MONOLITHIC_INSTALL 1)

# # This must be last
# include(CPack)
