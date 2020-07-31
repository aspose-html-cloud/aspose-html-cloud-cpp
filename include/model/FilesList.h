#ifndef COM_ASPOSE_MODEL_FilesList_H_
#define COM_ASPOSE_MODEL_FilesList_H_

#include "ModelBase.h"
#include "StorageFile.h"
#include <vector>
#include <cpprest/json.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// Files list
/// </summary>
class  FilesList : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT FilesList();
    ASPOSE_DLL_EXPORT ~FilesList();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT std::string toString() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FilesList members

    /// <summary>
    /// Files and folders contained by folder StorageFile.
    /// </summary>
    ASPOSE_DLL_EXPORT std::vector<std::shared_ptr<StorageFile>>& getValue();
    ASPOSE_DLL_EXPORT bool valueIsSet() const;
    ASPOSE_DLL_EXPORT void unsetValue();
    ASPOSE_DLL_EXPORT void setValue(std::vector<std::shared_ptr<StorageFile>> value);

protected:
    std::vector<std::shared_ptr<StorageFile>> m_Value;
    bool m_ValueIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FilesList_H_ */
