#ifndef COM_ASPOSE_MODEL_HttpContent_H_
#define COM_ASPOSE_MODEL_HttpContent_H_


#include <memory>

//Equal U in boost and in cpprest
#undef U

#include <cpprest/details/basic_types.h>
#include "defines.h"


namespace com {
namespace aspose {
namespace model {

class HttpContent
{
public:
    ASPOSE_DLL_EXPORT HttpContent();
    ASPOSE_DLL_EXPORT HttpContent(const utility::string_t &path, const utility::string_t &name);

    ASPOSE_DLL_EXPORT ~HttpContent();

    ASPOSE_DLL_EXPORT utility::string_t getContentDisposition();
    ASPOSE_DLL_EXPORT void setContentDisposition( const utility::string_t& value );

    ASPOSE_DLL_EXPORT utility::string_t getName();
    ASPOSE_DLL_EXPORT void setName( const utility::string_t& value );

    ASPOSE_DLL_EXPORT utility::string_t getFileName();
    ASPOSE_DLL_EXPORT void setFileName( const utility::string_t& value );

    ASPOSE_DLL_EXPORT utility::string_t getContentType();
    ASPOSE_DLL_EXPORT void setContentType( const utility::string_t& value );

    ASPOSE_DLL_EXPORT std::shared_ptr<std::istream> getData();
    ASPOSE_DLL_EXPORT void setData( std::shared_ptr<std::istream> value );

    ASPOSE_DLL_EXPORT void writeTo( std::ostream& stream );

private:
    // NOTE: no utility::string_t here because those strings can only contain ascii
    utility::string_t m_ContentDisposition;
    utility::string_t m_Name;
    utility::string_t m_FileName;
    utility::string_t m_ContentType;
    std::shared_ptr<std::istream> m_Data;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_HttpContent_H_ */
