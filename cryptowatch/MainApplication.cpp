#include <iostream>

#include "MainApplication.h"
#include "Crypto/Bitcoin.h"
#include "Crypto/Ethereum.h"

namespace SoftwrDev {
    void MainApplication::run(const std::string& currency) {
        if(currency == "btc") {
            SoftwrDev::Bitcoin bitcoin;
            std::cout << bitcoin.getPrice() << "\n";
            return;
        }
        if(currency == "eth") {
            SoftwrDev::Ethereum ethereum;
            std::cout << ethereum.getPrice() << "\n";
            return;
        }
        std::cout << "Invalid currency provided. Please provide a valid one...\n";
        exit(-1);
    }
}