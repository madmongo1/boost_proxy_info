cmake_minimum_required(VERSION 3.16...3.20)
project(boost_proxy_info)

find_package(Boost REQUIRED)

add_subdirectory(src)

add_library(boost_proxy_info ${boost_proxy_info_srcs})
target_link_libraries(boost_proxy_info PUBLIC Boost::boost)
target_include_directories(boost_proxy_info PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
add_library(Boost::proxy_info ALIAS boost_proxy_info)
set_property(TARGET boost_proxy_info PROPERTY EXPORT_NAME proxy_info)

add_subdirectory(example)
