/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FilesList.cpp">
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

#include "model/FilesList.h"

namespace com {
namespace aspose {
namespace model {

FilesList::FilesList()
{
    m_ValueIsSet = false;
}

FilesList::~FilesList()
{
}

void FilesList::validate()
{
    // TODO: implement validation
}

std::string FilesList::toString() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        for (auto& item : m_Value)
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if (jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("Value")] = web::json::value::array(jsonArray);
        }
    }

    return utility::conversions::to_utf8string(val.serialize());
}


web::json::value FilesList::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Value )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("Value")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FilesList::fromJson(web::json::value& val)
{
    {
        m_Value.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(utility::conversions::to_string_t("value")))
        {
        for( auto& item : val[utility::conversions::to_string_t("value")].as_array() )
        {
            if(item.is_null())
            {
                m_Value.push_back( std::shared_ptr<StorageFile>(nullptr) );
            }
            else
            {
                std::shared_ptr<StorageFile> newItem(new StorageFile());
                newItem->fromJson(item);
                m_Value.push_back( newItem );
            }
        }
        }
    }
}

void FilesList::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Value )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Value"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
}

void FilesList::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    {
        m_Value.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("Value")))
        {

        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Value"))));
        for( auto& item : jsonArray.as_array() )
        {
            if(item.is_null())
            {
                m_Value.push_back( std::shared_ptr<StorageFile>(nullptr) );
            }
            else
            {
                std::shared_ptr<StorageFile> newItem(new StorageFile());
                newItem->fromJson(item);
                m_Value.push_back( newItem );
            }
        }
        }
    }
}

std::vector<std::shared_ptr<StorageFile>>& FilesList::getValue()
{
    return m_Value;
}

void FilesList::setValue(std::vector<std::shared_ptr<StorageFile>> value)
{
    m_Value = value;
    m_ValueIsSet = true;
}
bool FilesList::valueIsSet() const
{
    return m_ValueIsSet;
}

void FilesList::unsetValue()
{
    m_ValueIsSet = false;
}

}
}
}

