#ifndef COM_ASPOSE_MODEL_ErrorDetails_H_
#define COM_ASPOSE_MODEL_ErrorDetails_H_

#include "ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// The error details
/// </summary>
class  ErrorDetails : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT ErrorDetails();
    ASPOSE_DLL_EXPORT ~ErrorDetails();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string ErrorDetails::toString() const override;

    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ErrorDetails members

    /// <summary>
    /// The request id
    /// </summary>
    ASPOSE_DLL_EXPORT utility::string_t getRequestId() const;
    ASPOSE_DLL_EXPORT bool requestIdIsSet() const;
    ASPOSE_DLL_EXPORT void unsetRequestId();
    ASPOSE_DLL_EXPORT void setRequestId(utility::string_t value);
    /// <summary>
    /// Date
    /// </summary>
    ASPOSE_DLL_EXPORT utility::datetime getDate() const;
    ASPOSE_DLL_EXPORT void setDate(utility::datetime value);

protected:
    utility::string_t m_RequestId;
    bool m_RequestIdIsSet;
    utility::datetime m_Date;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_ErrorDetails_H_ */
