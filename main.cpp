#include "cryptowatch/MainApplication.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "Missing currency argument. Please, provide one to continue...\n";
        exit(-1);
    }

    SoftwrDev::MainApplication app;
    app.run(argv[1]);
    return 0;
}