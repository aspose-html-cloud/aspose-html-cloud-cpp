#ifndef COM_ASPOSE_API_ApiClient_H_
#define COM_ASPOSE_API_ApiClient_H_


#include "ApiConfiguration.h"
#include "ApiException.h"
#include "IHttpBody.h"
#include "HttpContent.h"

#include <memory>
#include <vector>

#include <cpprest/details/basic_types.h>
#include <cpprest/http_client.h>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  ApiClient
{
public:
    ApiClient( std::shared_ptr<ApiConfiguration> configuration = nullptr );
    virtual ~ApiClient();

    std::shared_ptr<ApiConfiguration> getConfiguration() const;
    void setConfiguration(std::shared_ptr<ApiConfiguration> configuration);

    static utility::string_t parameterToString(utility::string_t value);
    static utility::string_t parameterToString(int32_t value);
    static utility::string_t parameterToString(int64_t value);
    static utility::string_t parameterToString(float value);
    static utility::string_t parameterToString(const utility::datetime &value);

    template<class T>
    static utility::string_t parameterToArrayString(std::vector<T> value)
    {
        utility::stringstream_t ss;

        for( size_t i = 0; i < value.size(); i++)
        {
            if( i > 0) ss << utility::conversions::to_string_t(", ");
            ss << ApiClient::parameterToString(value[i]);
        }

        return ss.str();
    }

    pplx::task<web::http::http_response> callApi(
        const utility::string_t& path,
        const utility::string_t& method,
        const std::map<utility::string_t, utility::string_t>& queryParams,
        const std::shared_ptr<IHttpBody> postBody,
        const std::map<utility::string_t, utility::string_t>& headerParams,
        const std::map<utility::string_t, utility::string_t>& formParams,
        const std::map<utility::string_t, std::shared_ptr<HttpContent>>& fileParams,
        const utility::string_t& contentType
    ) const;

protected:

    std::shared_ptr<ApiConfiguration> m_Configuration;
};

}
}
}

#endif /* COM_ASPOSE_API_ApiClient_H_ */
