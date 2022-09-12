#ifndef __OAUTH2__
#define __OAUTH2__


#include <cpprest/http_client.h>


namespace com {
	namespace aspose {
		namespace api {


			class OAuth2Token
			{
			public:
				OAuth2Token();
				~OAuth2Token();

				pplx::task<void> request_token(const utility::string_t& authPath, const utility::string_t& clientId, const utility::string_t& clientSecret);

				utility::string_t get_acc_token();
				utility::string_t get_refr_token();
				utility::string_t get_expires();
				utility::string_t get_issued();
				utility::string_t get_time_refr_min();
				utility::string_t get_token_type();
				int get_expires_in();

			private:
				utility::string_t read_response_body(web::http::http_response response);

				utility::string_t m_acc_token;
				utility::string_t m_refr_token;
				utility::string_t m_expires;
				utility::string_t m_issued;
				utility::string_t m_time_refr_min;
				utility::string_t m_token_type;
				int m_expires_in;

			};
		}
	}
}
#endif //__OAUTH2__
