#include <iostream>

#include "MainApplication.h"
#include "Crypto/Bitcoin.h"

namespace SoftwrDev {
    void MainApplication::run() {
        SoftwrDev::Bitcoin bitcoin;
        std::cout << "Price bitcoin in dolar: " << bitcoin.getPrice() << "\n";
    }
}