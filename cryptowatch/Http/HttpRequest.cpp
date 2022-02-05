#include "HttpRequest.h"

#include "curlpp/Easy.hpp"
#include "curlpp/Options.hpp"
#include <cstring>
#include <sstream>
#include "curlpp/cURLpp.hpp"

namespace SoftwrDev {
    HttpResponse HttpRequest::get() {
        using curlpp::options::Url;
        using curlpp::options::Header;
        using curlpp::options::Verbose;
        using curlpp::options::WriteStream;

        std::stringstream reqResponse;

        try {
            curlpp::Cleanup cleaner;
            curlpp::Easy myRequest;
            myRequest.setOpt<Url>(m_targetUrl);
            myRequest.setOpt(new Verbose(false));

            for(auto& m_header : m_headers) {
                myRequest.setOpt<Header>(m_header.c_str());
            }

            myRequest.setOpt(new WriteStream(&reqResponse));
            myRequest.perform();
        } catch(curlpp::RuntimeError& e) {
            std::cout << e.what() << std::endl;
        } catch(curlpp::LogicError& e) {
            std::cout << e.what() << std::endl;
        }

        std::string rawResponse = reqResponse.str();
        size_t endOfHeader = rawResponse.find("\r\n\r\n");

        if (endOfHeader != std::string::npos) {
            std::string header = rawResponse.substr(0, endOfHeader);
            std::string body = rawResponse.substr(endOfHeader + 4);

            HttpResponse response(header, body);
            return response;
        }

        HttpResponse response("", "");
        return response;
    }
}