#include "HttpResponse.h"

namespace SoftwrDev {
    std::string HttpResponse::body() {
        return m_body;
    }
    std::string HttpResponse::headers() {
        return m_headers;
    }
}