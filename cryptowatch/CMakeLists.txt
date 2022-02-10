cmake_minimum_required(VERSION 3.21)

project(libcryptowatch)

include_directories(
        curlpp lib/curlpp/include
)

add_library(
        libcryptowatch
        MainApplication.cpp
        Http/HttpResponse.cpp
        Http/HttpRequest.cpp
        Crypto/Bitcoin.cpp
        Crypto/Ethereum.cpp
)

add_subdirectory(lib/curlpp)

target_link_libraries(
        libcryptowatch
        PUBLIC curlpp
)