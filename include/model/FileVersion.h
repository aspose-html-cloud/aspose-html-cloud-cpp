#ifndef COM_ASPOSE_MODEL_FileVersion_H_
#define COM_ASPOSE_MODEL_FileVersion_H_


#include <cpprest/details/basic_types.h>
#include "model/File.h"

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class FileVersion : public File
{
public:
    ASPOSE_DLL_EXPORT FileVersion();
    ASPOSE_DLL_EXPORT ~FileVersion();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileVersion members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getVersionId() const;
    ASPOSE_DLL_EXPORT bool versionIdIsSet() const;
    ASPOSE_DLL_EXPORT void unsetVersionId();
    ASPOSE_DLL_EXPORT void setVersionId(utility::string_t value);
    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT bool isIsLatest() const;
    ASPOSE_DLL_EXPORT bool isLatestIsSet() const;
    ASPOSE_DLL_EXPORT void unsetIsLatest();
    ASPOSE_DLL_EXPORT void setIsLatest(bool value);

private:
    utility::string_t m_VersionId;
    bool m_VersionIdIsSet;
    bool m_IsLatest;
    bool m_IsLatestIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileVersion_H_ */
