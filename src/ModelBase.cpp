/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ModelBase.cpp">
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

#include "ModelBase.h"

namespace com {
namespace aspose {
namespace model {

ModelBase::ModelBase()
{
}
ModelBase::~ModelBase()
{
}

web::json::value ModelBase::toJson( const utility::string_t& value )
{
    return web::json::value::string(value);
}
web::json::value ModelBase::toJson( const utility::datetime& value )
{
    return web::json::value::string(value.to_string(utility::datetime::ISO_8601));
}
web::json::value ModelBase::toJson( int32_t value )
{
    return web::json::value::number(value);
}
web::json::value ModelBase::toJson( int64_t value )
{
    return web::json::value::number(value);
}
web::json::value ModelBase::toJson( double value )
{
    return web::json::value::number(value);
} 
web::json::value ModelBase::toJson(bool value) {
    return web::json::value::boolean(value);
}

web::json::value ModelBase::toJson( std::shared_ptr<HttpContent> content )
{
    web::json::value value;
    value[utility::conversions::to_string_t("ContentDisposition")] = ModelBase::toJson(content->getContentDisposition());
    value[utility::conversions::to_string_t("ContentType")] = ModelBase::toJson(content->getContentType());
    value[utility::conversions::to_string_t("FileName")] = ModelBase::toJson(content->getFileName());
    value[utility::conversions::to_string_t("InputStream")] = web::json::value::string( ModelBase::toBase64(content->getData()) );
    return value;
}

std::shared_ptr<HttpContent> ModelBase::fileFromJson(web::json::value& val)
{
    std::shared_ptr<HttpContent> content(new HttpContent);

    if(val.has_field(utility::conversions::to_string_t("ContentDisposition")))
    {
        content->setContentDisposition( ModelBase::stringFromJson(val[utility::conversions::to_string_t("ContentDisposition")]) );
    }
    if(val.has_field(utility::conversions::to_string_t("ContentType")))
    {
        content->setContentType( ModelBase::stringFromJson(val[utility::conversions::to_string_t("ContentType")]) );
    }
    if(val.has_field(utility::conversions::to_string_t("FileName")))
    {
        content->setFileName( ModelBase::stringFromJson(val[utility::conversions::to_string_t("FileName")]) );
    }
    if(val.has_field(utility::conversions::to_string_t("InputStream")))
    {
        content->setData( ModelBase::fromBase64( ModelBase::stringFromJson(val[utility::conversions::to_string_t("InputStream")]) ) );
    }

    return content;
}

web::json::value ModelBase::toJson( std::shared_ptr<ModelBase> content )
{
    return content.get() ? content->toJson() : web::json::value::null();
}

std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const utility::string_t& value, const utility::string_t& contentType)
{
    std::shared_ptr<HttpContent> content(new HttpContent);
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string(value) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const utility::datetime& value, const utility::string_t& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string(value.to_string(utility::datetime::ISO_8601) ) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, std::shared_ptr<HttpContent> value )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( value->getContentDisposition() );
    content->setContentType( value->getContentType() );
    content->setData( value->getData() );
    content->setFileName( value->getFileName() );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const web::json::value& value, const utility::string_t& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::istream>( new std::stringstream( utility::conversions::to_utf8string(value.serialize()) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, int32_t value, const utility::string_t& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
	std::stringstream* valueAsStringStream = new std::stringstream();
	(*valueAsStringStream) << value;
    content->setData( std::shared_ptr<std::istream>( valueAsStringStream ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, int64_t value, const utility::string_t& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
	std::stringstream* valueAsStringStream = new std::stringstream();
	(*valueAsStringStream) << value;
    content->setData( std::shared_ptr<std::istream>( valueAsStringStream) ) ;
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, double value, const utility::string_t& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( utility::conversions::to_string_t("form-data") );
    content->setContentType( contentType );
	std::stringstream* valueAsStringStream = new std::stringstream();
	(*valueAsStringStream) << value;
    content->setData( std::shared_ptr<std::istream>( valueAsStringStream ) );
    return content;
}

// base64 encoding/decoding based on : https://en.wikibooks.org/wiki/Algorithm_Implementation/Miscellaneous/Base64#C.2B.2B
const static char Base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const static char Base64PadChar = '=';
utility::string_t ModelBase::toBase64( utility::string_t value )
{
    std::shared_ptr<std::istream> source( new std::stringstream( utility::conversions::to_utf8string(value) ) );
    return ModelBase::toBase64(source);
}
utility::string_t ModelBase::toBase64( std::shared_ptr<std::istream> value )
{
    value->seekg( 0, value->end );
    size_t length = value->tellg();
    value->seekg( 0, value->beg );
    utility::string_t base64;
    base64.reserve( ((length / 3) + (length % 3 > 0)) * 4 );
    char read[3] = { 0 };
    uint32_t temp;
    for ( size_t idx = 0; idx < length / 3; idx++ )
    {
        value->read( read, 3 );
        temp = (read[0]) << 16;
        temp += (read[1]) << 8;
        temp += (read[2]);
        base64.append( 1, Base64Chars[(temp & 0x00FC0000) >> 18] );
        base64.append( 1, Base64Chars[(temp & 0x0003F000) >> 12] );
        base64.append( 1, Base64Chars[(temp & 0x00000FC0) >> 6] );
        base64.append( 1, Base64Chars[(temp & 0x0000003F)] );
    }
    switch ( length % 3 )
    {
        case 1:
            value->read( read, 1 );
            temp = read[0] << 16;
            base64.append( 1, Base64Chars[(temp & 0x00FC0000) >> 18] );
            base64.append( 1, Base64Chars[(temp & 0x0003F000) >> 12] );
            base64.append( 2, Base64PadChar );
            break;
        case 2:
            value->read( read, 2 );
            temp = read[0] << 16;
            temp += read[1] << 8;
            base64.append( 1, Base64Chars[(temp & 0x00FC0000) >> 18] );
            base64.append( 1, Base64Chars[(temp & 0x0003F000) >> 12] );
            base64.append( 1, Base64Chars[(temp & 0x00000FC0) >> 6] );
            base64.append( 1, Base64PadChar );
            break;
    }
    return base64;
}


std::shared_ptr<std::istream> ModelBase::fromBase64( const utility::string_t& encoded )
{
    std::shared_ptr<std::stringstream> result(new std::stringstream);

    char outBuf[3] = { 0 };
    uint32_t temp = 0;

    utility::string_t::const_iterator cursor = encoded.begin();
    while ( cursor < encoded.end() )
    {
        for ( size_t quantumPosition = 0; quantumPosition < 4; quantumPosition++ )
        {
            temp <<= 6;
            if ( *cursor >= 0x41 && *cursor <= 0x5A )
            {
                temp |= *cursor - 0x41;
            }
            else if ( *cursor >= 0x61 && *cursor <= 0x7A )
            {
                temp |= *cursor - 0x47;
            }
            else if ( *cursor >= 0x30 && *cursor <= 0x39 )
            {
                temp |= *cursor + 0x04;
            }
            else if ( *cursor == 0x2B )
            {
                temp |= 0x3E; //change to 0x2D for URL alphabet
            }
            else if ( *cursor == 0x2F )
            {
                temp |= 0x3F; //change to 0x5F for URL alphabet
            }
            else if ( *cursor == Base64PadChar ) //pad
            {
                switch ( encoded.end() - cursor )
                {
                    case 1: //One pad character
                        outBuf[0] = (temp >> 16) & 0x000000FF;
                        outBuf[1] = (temp >> 8) & 0x000000FF;
                        result->write( outBuf, 2 );
                        return result;
                    case 2: //Two pad characters
                        outBuf[0] = (temp >> 10) & 0x000000FF;
                        result->write( outBuf, 1 );
                        return result;
                    default:
                        throw web::json::json_exception( utility::conversions::to_string_t( "Invalid Padding in Base 64!" ).c_str() );
                }
            }
            else
            {
                throw web::json::json_exception( utility::conversions::to_string_t( "Non-Valid Character in Base 64!" ).c_str() );
            }
            ++cursor;
        }

        outBuf[0] = (temp >> 16) & 0x000000FF;
        outBuf[1] = (temp >> 8) & 0x000000FF;
        outBuf[2] = (temp) & 0x000000FF;
        result->write( outBuf, 3 );
    }

    return result;
}

int64_t ModelBase::int64_tFromJson(web::json::value& val)
{
    return val.as_number().to_int64();
}
int32_t ModelBase::int32_tFromJson(web::json::value& val)
{
    return val.as_integer();
}
float ModelBase::floatFromJson(web::json::value& val)
{
    return static_cast<float>(val.as_double());
}
utility::string_t ModelBase::stringFromJson(web::json::value& val)
{
    return val.is_string() ? val.as_string() : utility::conversions::to_string_t("");
}

utility::datetime ModelBase::dateFromJson(web::json::value& val)
{
    return utility::datetime::from_string(val.as_string(), utility::datetime::ISO_8601);
}
bool ModelBase::boolFromJson(web::json::value& val)
{
    return val.as_bool();
}
double ModelBase::doubleFromJson(web::json::value& val)
{
    return val.as_double();
}

int64_t ModelBase::int64_tFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);

    utility::stringstream_t ss(str);
    int64_t result = 0;
    ss >> result;
    return result;
}
int32_t ModelBase::int32_tFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);

    utility::stringstream_t ss(str);
    int32_t result = 0;
    ss >> result;
    return result;
}
float ModelBase::floatFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);

    utility::stringstream_t ss(str);
    float result = 0;
    ss >> result;
    return result;
}
utility::string_t ModelBase::stringFromHttpContent(std::shared_ptr<HttpContent> val)
{
    std::shared_ptr<std::istream> data = val->getData();
    data->seekg( 0, data->beg );

    std::string str((std::istreambuf_iterator<char>(*data.get())),
                 std::istreambuf_iterator<char>());

    return utility::conversions::to_string_t(str);
}
utility::datetime ModelBase::dateFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);
    return utility::datetime::from_string(str, utility::datetime::ISO_8601);
}

bool ModelBase::boolFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);

    utility::stringstream_t ss(str);
    bool result = false;
    ss >> result;
    return result;
}
double ModelBase::doubleFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);

    utility::stringstream_t ss(str);
    double result = 0.0;
    ss >> result;
    return result;
}

web::json::value ModelBase::valueFromHttpContent(std::shared_ptr<HttpContent> val)
{
    utility::string_t str = ModelBase::stringFromHttpContent(val);
    return web::json::value::parse(str);
}

}
}
}
