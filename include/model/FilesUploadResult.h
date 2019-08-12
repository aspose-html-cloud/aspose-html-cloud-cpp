#ifndef COM_ASPOSE_MODEL_FilesUploadResult_H_
#define COM_ASPOSE_MODEL_FilesUploadResult_H_

#include "ModelBase.h"
#include <cpprest/details/basic_types.h>
#include "model/Error.h"
#include <vector>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// File upload result
/// </summary>
class  FilesUploadResult : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT FilesUploadResult();
    ASPOSE_DLL_EXPORT ~FilesUploadResult();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FilesUploadResult members

    /// <summary>
    /// List of uploaded file names
    /// </summary>
    ASPOSE_DLL_EXPORT std::vector<utility::string_t>& getUploaded();
    ASPOSE_DLL_EXPORT bool uploadedIsSet() const;
    ASPOSE_DLL_EXPORT void unsetUploaded();
    ASPOSE_DLL_EXPORT void setUploaded(std::vector<utility::string_t> value);
    /// <summary>
    /// List of errors.
    /// </summary>
    ASPOSE_DLL_EXPORT std::vector<std::shared_ptr<Error>>& getErrors();
    ASPOSE_DLL_EXPORT bool errorsIsSet() const;
    ASPOSE_DLL_EXPORT void unsetErrors();
    ASPOSE_DLL_EXPORT void setErrors(std::vector<std::shared_ptr<Error>> value);

protected:
    std::vector<utility::string_t> m_Uploaded;
    bool m_UploadedIsSet;
    std::vector<std::shared_ptr<Error>> m_Errors;
    bool m_ErrorsIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FilesUploadResult_H_ */
