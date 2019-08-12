#ifndef COM_ASPOSE_MODEL_Error_H_
#define COM_ASPOSE_MODEL_Error_H_

#include "ModelBase.h"
#include "model/ErrorDetails.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// Error
/// </summary>
class  Error : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT Error();
    ASPOSE_DLL_EXPORT ~Error();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Error members

    /// <summary>
    /// Code             
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getCode() const;
    ASPOSE_DLL_EXPORT bool codeIsSet() const;
    ASPOSE_DLL_EXPORT void unsetCode();
    ASPOSE_DLL_EXPORT void setCode(utility::string_t value);
    /// <summary>
    /// Message             
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getMessage() const;
    ASPOSE_DLL_EXPORT bool messageIsSet() const;
    ASPOSE_DLL_EXPORT void unsetMessage();
    ASPOSE_DLL_EXPORT void setMessage(utility::string_t value);
    /// <summary>
    /// Description             
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getDescription() const;
    ASPOSE_DLL_EXPORT bool descriptionIsSet() const;
    ASPOSE_DLL_EXPORT void unsetDescription();
    ASPOSE_DLL_EXPORT void setDescription(utility::string_t value);
    /// <summary>
    /// Inner Error             
    /// </summary>
    ASPOSE_DLL_EXPORT std::shared_ptr<ErrorDetails> getInnerError() const;
    ASPOSE_DLL_EXPORT bool innerErrorIsSet() const;
    ASPOSE_DLL_EXPORT void unsetInnerError();
    ASPOSE_DLL_EXPORT void setInnerError(std::shared_ptr<ErrorDetails> value);

protected:
    utility::string_t m_Code;
    bool m_CodeIsSet;
    utility::string_t m_Message;
    bool m_MessageIsSet;
    utility::string_t m_Description;
    bool m_DescriptionIsSet;
    std::shared_ptr<ErrorDetails> m_InnerError;
    bool m_InnerErrorIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_Error_H_ */
