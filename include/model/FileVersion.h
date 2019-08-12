#ifndef COM_ASPOSE_MODEL_FileVersion_H_
#define COM_ASPOSE_MODEL_FileVersion_H_

#include "model/StorageFile.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// File Version
/// </summary>
class  FileVersion : public StorageFile
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
    /// File Version ID.
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getVersionId() const;
    ASPOSE_DLL_EXPORT bool versionIdIsSet() const;
    ASPOSE_DLL_EXPORT void unsetVersionId();
    ASPOSE_DLL_EXPORT void setVersionId(utility::string_t value);
    /// <summary>
    /// Specifies whether the file is (true) or is not (false) the latest version of an file.
    /// </summary>
    ASPOSE_DLL_EXPORT bool isIsLatest() const;
    ASPOSE_DLL_EXPORT void setIsLatest(bool value);

protected:
    utility::string_t m_VersionId;
    bool m_VersionIdIsSet;
    bool m_IsLatest;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_FileVersion_H_ */
