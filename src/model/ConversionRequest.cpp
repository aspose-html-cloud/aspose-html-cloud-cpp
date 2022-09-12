/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ConversionRequest.cpp">
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

#include "model/ConversionRequest.h"

namespace com {
namespace aspose {
namespace model {

	ConversionRequest::ConversionRequest() {}
	ConversionRequest::~ConversionRequest() {}

	/// ModelBase overrides
	void ConversionRequest::validate() {}
	web::json::value ConversionRequest::toJson() const
	{
		web::json::value val = web::json::value::object();

		val[utility::conversions::to_string_t("InputPath")] = ModelBase::toJson(m_inputPath);
		val[utility::conversions::to_string_t("OutputFile")] = ModelBase::toJson(m_outputPath);

		if (m_storageName)
		{
			val[utility::conversions::to_string_t("StorageName")] = ModelBase::toJson(m_storageName.get());
		}
		if (m_options)
		{
			val[utility::conversions::to_string_t("Options")] = m_options->toJson();
		}
		return val;
	}

	void ConversionRequest::fromJson(web::json::value& json) {}
	
	std::string ConversionRequest::toString() const
	{
		auto val = toJson().serialize();
		return utility::conversions::to_utf8string(val);
	}

	void ConversionRequest::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const {}
	void ConversionRequest::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) {}

	// Setters
	ConversionRequest* ConversionRequest::setInputPath(const utility::string_t& value)
	{
		m_inputPath = value;
		return this;
	}
	ConversionRequest* ConversionRequest::setOutputFile(const utility::string_t& value)
	{
		m_outputPath = value;
		return this;
	}
	ConversionRequest* ConversionRequest::setStorageName(const utility::string_t& value)
	{
		m_storageName = value;
		return this;
	}
	ConversionRequest* ConversionRequest::setOptions(const std::shared_ptr<ConversionOptions> value)
	{
		m_options = value;
		return this;
	}

}
}
}