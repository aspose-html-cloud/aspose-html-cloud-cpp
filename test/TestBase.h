#ifndef __TestBase__
#define __TestBase__

#include "AsposeHtmlCloud.h"
//Equal U in boost, cpprest, gtest
#undef U
#include "gtest/gtest.h"

class TestBase : public ::testing::Test
{
public:

	TestBase();
	~TestBase();

    static const utility::string_t clientId;
    static const utility::string_t clientSecret;
    static const utility::string_t basePath;
    static const utility::string_t authPath;
    static const utility::string_t testSource;
    static const utility::string_t testResult;

	static bool save_to_file(com::aspose::model::HttpContent content, utility::string_t file_name);
};
#endif // __TestBase__
