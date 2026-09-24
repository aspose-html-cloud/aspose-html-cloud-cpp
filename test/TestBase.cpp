/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestBase.cpp">
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
#include "TestBase.h"

#include <cstdio>
#include <cstdlib>
#include <string>

namespace
{
	// Reads a setting from the environment. When `fallback` is nullptr the
	// setting is required: credentials are never stored in the repository, so
	// set ASPOSE_CLIENT_ID and ASPOSE_CLIENT_SECRET (or the APP_SID / APP_KEY
	// aliases) before running the suite; the SDK test agent does this
	// automatically.
	utility::string_t setting_from_env(const char* primary, const char* secondary, const char* fallback)
	{
		const char* names[] = { primary, secondary };

		for (const char* name : names)
		{
			if (name == nullptr)
			{
				continue;
			}

			const char* value = std::getenv(name);
			if (value != nullptr && *value != '\0')
			{
				return utility::conversions::to_string_t(std::string(value));
			}
		}

		if (fallback == nullptr)
		{
			// Runs during static initialisation, where an exception would only
			// surface as an unexplained std::terminate.
			std::fprintf(stderr, "Missing Aspose Cloud credentials: set %s%s%s in the environment.\n",
				primary, secondary ? " or " : "", secondary ? secondary : "");
			std::exit(2);
		}

		return utility::conversions::to_string_t(std::string(fallback));
	}
}

TestBase::TestBase()
{
}

TestBase::~TestBase()
{
}

// Endpoints are fixed; ASPOSE_API_BASE_URL is not used because the value the
// test agent exports has no /v4.0 segment.
const utility::string_t TestBase::basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
const utility::string_t TestBase::authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
const utility::string_t TestBase::clientId = setting_from_env("ASPOSE_CLIENT_ID", "APP_SID", nullptr);
const utility::string_t TestBase::clientSecret = setting_from_env("ASPOSE_CLIENT_SECRET", "APP_KEY", nullptr);

// Relative to the working directory the tests are started from (the repository
// root), unless overridden through the environment.
const utility::string_t TestBase::testSource = setting_from_env("ASPOSE_TEST_SOURCE", nullptr, "testsource\\");
const utility::string_t TestBase::testResult = setting_from_env("ASPOSE_TEST_RESULT", nullptr, "testresult\\");

bool TestBase::save_to_file(com::aspose::model::HttpContent content, utility::string_t name)
{
	std::ofstream saved_data(name, std::ios::out | std::ios::binary);

	//Save file locally
	if (saved_data.is_open())
	{
		content.writeTo(saved_data);
		saved_data.close();
		return true;
	}
	else
	{
		std::cout << "Unable to open file";
		return false;
	}
}
