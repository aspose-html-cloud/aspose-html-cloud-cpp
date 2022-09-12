/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OAuth2Token.cpp">
*  Copyright (c) 2022 Aspose.HTML for Cloud
* </copyright>
* <summary>
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary>
* --------------------------------------------------------------------------------------------------------------------
*/


#include "OAuth2Token.h"


namespace com {
	namespace aspose {
		namespace api {


			OAuth2Token::OAuth2Token()
			{
			}

			pplx::task<void> OAuth2Token::request_token(const utility::string_t& authPath, const utility::string_t& clientId, const utility::string_t& clientSecret)
			{
				web::http::client::http_client client(authPath);
				utility::string_t postData = _XPLATSTR("client_id=") + clientId + _XPLATSTR("&client_secret=") + clientSecret + _XPLATSTR("&grant_type=client_credentials");
				web::http::http_request request(web::http::methods::POST);
				request.headers().add(_XPLATSTR("Content-Type"), _XPLATSTR("application/x-www-form-urlencoded"));
				request.headers().add(_XPLATSTR("Accept"), _XPLATSTR("application/json"));
				request.set_body(postData);

				return client.request(request).then([=](web::http::http_response response)
				{
					int status = response.status_code();

					if (status == 200) {
						utility::string_t target = read_response_body(response);
						std::error_code err;
						web::json::value answer = web::json::value::parse(target.c_str(), err);
						if (err.value() == 0) {
							m_acc_token = answer[_XPLATSTR("access_token")].as_string();
/*
                            m_refr_token = answer[_XPLATSTR("refresh_token")].as_string();
							m_expires = answer[_XPLATSTR(".expires")].as_string();
							m_issued = answer[_XPLATSTR(".issued")].as_string();
							m_time_refr_min = answer[_XPLATSTR("clientRefreshTokenLifeTimeInMinutes")].as_string();
							m_token_type = answer[_XPLATSTR("token_type")].as_string();
							m_expires_in = answer[_XPLATSTR("expires_in")].as_integer();
	*/				
                        }
					}
				});
			}

			utility::string_t OAuth2Token::get_acc_token()
			{
				return m_acc_token;
			}

			utility::string_t OAuth2Token::get_refr_token()
			{
				return m_refr_token;
			}

			utility::string_t OAuth2Token::get_expires()
			{
				return m_expires;
			}

			utility::string_t OAuth2Token::get_issued()
			{
				return m_issued;
			}

			utility::string_t OAuth2Token::get_time_refr_min()
			{
				return m_time_refr_min;
			}

			utility::string_t OAuth2Token::get_token_type()
			{
				return m_token_type;
			}

			int OAuth2Token::get_expires_in()
			{
				return m_expires_in;
			}

			utility::string_t OAuth2Token::read_response_body(web::http::http_response response)
			{
				auto bodyStream = response.body();
				concurrency::streams::stringstreambuf sb;
				auto& target = sb.collection();
				bodyStream.read_to_end(sb).get();
#ifdef _WIN32 // Windows uses UNICODE but result is in UTF8, so we need to convert it
				utility::string_t wtarget;
				wtarget.assign(target.begin(), target.end());
				return wtarget;
#else
				return target;
#endif
			}

			OAuth2Token::~OAuth2Token()
			{
			}
		}
	}
}