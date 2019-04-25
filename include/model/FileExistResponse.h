#ifndef COM_ASPOSE_MODEL_FileExistResponse_H_
#define COM_ASPOSE_MODEL_FileExistResponse_H_


#include "MessageResponse.h"
#include "model/FileExist.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class FileExistResponse : public MessageResponse
{
public:
    ASPOSE_DLL_EXPORT FileExistResponse();
    ASPOSE_DLL_EXPORT ~FileExistResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileExistResponse members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT std::shared_ptr<FileExist> getFileExist() const;
    ASPOSE_DLL_EXPORT bool fileExistIsSet() const;
    ASPOSE_DLL_EXPORT void unsetFileExist();
    ASPOSE_DLL_EXPORT void setFileExist(std::shared_ptr<FileExist> value);

private:
    std::shared_ptr<FileExist> m_FileExist;
    bool m_FileExistIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileExistResponse_H_ */
