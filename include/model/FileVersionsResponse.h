#ifndef COM_ASPOSE_MODEL_FileVersionsResponse_H_
#define COM_ASPOSE_MODEL_FileVersionsResponse_H_


#include "MessageResponse.h"
#include "model/FileVersion.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class FileVersionsResponse : public MessageResponse
{
public:
    ASPOSE_DLL_EXPORT FileVersionsResponse();
    ASPOSE_DLL_EXPORT ~FileVersionsResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileVersionsResponse members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT std::vector<std::shared_ptr<FileVersion>>& getFileVersions();
    ASPOSE_DLL_EXPORT bool fileVersionsIsSet() const;
    ASPOSE_DLL_EXPORT void unsetFileVersions();
    ASPOSE_DLL_EXPORT void setFileVersions(std::vector<std::shared_ptr<FileVersion>> value);

private:
    std::vector<std::shared_ptr<FileVersion>> m_FileVersions;
    bool m_FileVersionsIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileVersionsResponse_H_ */
