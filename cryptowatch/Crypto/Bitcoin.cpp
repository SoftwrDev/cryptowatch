#include "Bitcoin.h"

#include <string>
#include <vector>
#include <regex>

#include "../Http/HttpRequest.h"

namespace SoftwrDev {
    std::string Bitcoin::getPrice() {
        std::vector<std::string> headers;
        headers.emplace_back("authority: www.binance.com");
        headers.emplace_back("upgrade-insecure-requests: 1");
        headers.emplace_back("user-agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36");

        HttpRequest request("https://www.binance.com/en/price/bitcoin", headers);
        auto response = request.get();

        std::string responseBody = response.body();

        const std::regex r(R"(\$\s+?[0-9]+\,?[0-9]+\.?[0-9]+)");
        std::smatch m;

        if (std::regex_search(responseBody, m, r)) {
            return m[0];
        }

        return "";
    }
}