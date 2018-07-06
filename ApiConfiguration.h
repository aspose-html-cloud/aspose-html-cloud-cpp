#ifndef COM_ASPOSE_API_ApiConfiguration_H_
#define COM_ASPOSE_API_ApiConfiguration_H_



#include <map>

#include <cpprest/details/basic_types.h>
#include <cpprest/http_client.h>
namespace com {
namespace aspose {
namespace api {

class  ApiConfiguration
{
public:
    ApiConfiguration();
	ApiConfiguration(const utility::string_t& clientId, const utility::string_t& clientSecret, const utility::string_t& basePath, const utility::string_t& authPath);
	virtual ~ApiConfiguration();

    web::http::client::http_client_config& getHttpConfig();
    void setHttpConfig( web::http::client::http_client_config& value );

    utility::string_t getBaseUrl() const;
    void setBaseUrl( const utility::string_t value );

    utility::string_t getUserAgent() const;
    void setUserAgent( const utility::string_t value );

    std::map<utility::string_t, utility::string_t>& getDefaultHeaders();
	void setDefaultHeader(const utility::string_t, const utility::string_t);


    utility::string_t getApiKey( const utility::string_t& prefix) const;
    void setApiKey( const utility::string_t& prefix, const utility::string_t& apiKey );

protected:
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
