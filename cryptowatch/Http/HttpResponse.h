#ifndef CRYPTO_WATCH_HTTPRESPONSE_H
#define CRYPTO_WATCH_HTTPRESPONSE_H

#include <string>
#include <utility>

namespace SoftwrDev {
    class HttpResponse {
    private:
        std::string m_headers;
        std::string m_body;
    public:
        HttpResponse(std::string  headers, std::string  body)
            : m_headers(std::move(headers)), m_body(std::move(body)) {}
        std::string headers();
        std::string body();
    };
}


#endif //CRYPTO_WATCH_HTTPRESPONSE_H
