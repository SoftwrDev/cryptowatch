#ifndef CRYPTO_WATCH_HTTPREQUEST_H
#define CRYPTO_WATCH_HTTPREQUEST_H

#include <string>
#include <utility>
#include <vector>

#include "HttpResponse.h"

using std::string;

namespace SoftwrDev {
    class HttpRequest {
    private:
        string m_targetUrl;
        std::vector<string> m_headers;
    public:
        HttpRequest(string  targetUrl, std::vector<string>  headers):
            m_targetUrl(std::move(targetUrl)),
            m_headers(std::move(headers)) {}
        HttpResponse get();
    };
}

#endif //CRYPTO_WATCH_HTTPREQUEST_H
