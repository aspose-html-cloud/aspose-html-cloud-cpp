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

#include <cstdlib>
#include <string>

namespace
{
	// Reads a setting from the environment, falling back to a literal so the
	// suite still runs on a developer machine without any extra setup.
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

		return utility::conversions::to_string_t(std::string(fallback));
	}
}

TestBase::TestBase()
{
}

TestBase::~TestBase()
{
}

const utility::string_t TestBase::basePath = setting_from_env("ASPOSE_API_BASE_URL", nullptr, "https://api.aspose.cloud/v4.0");
const utility::string_t TestBase::authPath = setting_from_env("ASPOSE_AUTH_URL", nullptr, "https://api.aspose.cloud/connect/token");
const utility::string_t TestBase::clientId = setting_from_env("ASPOSE_CLIENT_ID", "APP_SID", "2225baa2-097b-4731-9831-d0d56c28230f");
const utility::string_t TestBase::clientSecret = setting_from_env("ASPOSE_CLIENT_SECRET", "APP_KEY", "c8dda7d6445d82635b8797d1c8edd153");

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
