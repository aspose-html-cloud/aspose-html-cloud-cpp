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


TestBase::TestBase()
{
}

TestBase::~TestBase()
{
}

const utility::string_t TestBase::basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
const utility::string_t TestBase::authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");
const utility::string_t TestBase::clientId = _XPLATSTR("2225baa2-097b-4731-9831-d0d56c28230f");
const utility::string_t TestBase::clientSecret = _XPLATSTR("c8dda7d6445d82635b8797d1c8edd153");

//const utility::string_t TestBase::basePath = _XPLATSTR("http://localhost:5000/v4.0");
//const utility::string_t TestBase::authPath = _XPLATSTR("https://api-qa.aspose.cloud/connect/token");
//const utility::string_t TestBase::clientId = _XPLATSTR("html.cloud");
//const utility::string_t TestBase::clientSecret = _XPLATSTR("html.cloud");

const utility::string_t TestBase::testSource = _XPLATSTR("e:\\WORK\\HTML\\Cloud\\aspose-html-cloud-cpp\\testsource\\");
const utility::string_t TestBase::testResult = _XPLATSTR("e:\\WORK\\HTML\\Cloud\\aspose-html-cloud-cpp\\testresult\\");

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
