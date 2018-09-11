#ifndef __TestBase__
#define __TestBase__


#include "pch.h"
#include "HttpContent.h"

class TestBase : public ::testing::Test
{
public:

	TestBase();
	~TestBase();

	const utility::string_t clientId = _XPLATSTR("XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX");
	const utility::string_t clientSecret = _XPLATSTR("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v1.1");
	const utility::string_t authPath = _XPLATSTR("http://api.aspose.cloud/oauth2/token");

	const utility::string_t testSource = _XPLATSTR("..\\testsource\\");
	const utility::string_t testResult = _XPLATSTR("..\\testresult\\");

	static bool save_to_file(com::aspose::model::HttpContent content, utility::string_t file_name);
};

#endif // __TestBase__