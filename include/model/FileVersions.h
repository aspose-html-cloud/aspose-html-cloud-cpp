#ifndef COM_ASPOSE_MODEL_FileVersions_H_
#define COM_ASPOSE_MODEL_FileVersions_H_

#include "ModelBase.h"
#include "model/FileVersion.h"
#include <vector>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// File versions FileVersion.
/// </summary>
class  FileVersions : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT FileVersions();
    ASPOSE_DLL_EXPORT ~FileVersions();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileVersions members

    /// <summary>
    /// File versions FileVersion.
    /// </summary>
    ASPOSE_DLL_EXPORT std::vector<std::shared_ptr<FileVersion>>& getValue();
    ASPOSE_DLL_EXPORT bool valueIsSet() const;
    ASPOSE_DLL_EXPORT void unsetValue();
    ASPOSE_DLL_EXPORT void setValue(std::vector<std::shared_ptr<FileVersion>> value);

protected:
    std::vector<std::shared_ptr<FileVersion>> m_Value;
    bool m_ValueIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileVersions_H_ */
