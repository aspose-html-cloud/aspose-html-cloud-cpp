#ifndef COM_ASPOSE_API_ApiConfiguration_H_
#define COM_ASPOSE_API_ApiConfiguration_H_


#include <map>
#include <cpprest/details/basic_types.h>
#include <cpprest/http_client.h>
#include "defines.h"


namespace com {
namespace aspose {
namespace api {

class ApiConfiguration
{
public:
    ASPOSE_DLL_EXPORT ApiConfiguration(const utility::string_t& clientId, const utility::string_t& clientSecret, const utility::string_t& basePath, const utility::string_t& authPath);
    ASPOSE_DLL_EXPORT virtual ~ApiConfiguration();

    ASPOSE_DLL_EXPORT web::http::client::http_client_config& getHttpConfig();
    ASPOSE_DLL_EXPORT void setHttpConfig( web::http::client::http_client_config& value );

    ASPOSE_DLL_EXPORT utility::string_t getBaseUrl() const;
    ASPOSE_DLL_EXPORT void setBaseUrl( const utility::string_t value );

    ASPOSE_DLL_EXPORT utility::string_t getUserAgent() const;
    ASPOSE_DLL_EXPORT void setUserAgent( const utility::string_t value );

    ASPOSE_DLL_EXPORT std::map<utility::string_t, utility::string_t>& getDefaultHeaders();
    ASPOSE_DLL_EXPORT void setDefaultHeader(const utility::string_t, const utility::string_t);


    ASPOSE_DLL_EXPORT utility::string_t getApiKey( const utility::string_t& prefix) const;
    ASPOSE_DLL_EXPORT void setApiKey( const utility::string_t& prefix, const utility::string_t& apiKey );

private:
    utility::string_t m_BaseUrl;
    std::map<utility::string_t, utility::string_t> m_DefaultHeaders;
    std::map<utility::string_t, utility::string_t> m_ApiKeys;
    web::http::client::http_client_config m_HttpConfig;
    utility::string_t m_UserAgent;


};

}
}
}
#endif /* COM_ASPOSE_API_ApiConfiguration_H_ */
