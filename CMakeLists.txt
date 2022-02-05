cmake_minimum_required(VERSION 3.21)
project(crypto_watch)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(cryptowatch)

add_executable(crypto_watch main.cpp)

target_link_libraries(
        crypto_watch
        PUBLIC libcryptowatch
)
