#ifndef COM_ASPOSE_MODEL_DiscUsage_H_
#define COM_ASPOSE_MODEL_DiscUsage_H_


#include "ModelBase.h"


namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class DiscUsage : public ModelBase
{
public:
    ASPOSE_DLL_EXPORT DiscUsage();
    ASPOSE_DLL_EXPORT ~DiscUsage();

    /////////////////////////////////////////////
    /// ModelBase overrides

    ASPOSE_DLL_EXPORT void validate() override;

    ASPOSE_DLL_EXPORT web::json::value toJson() const override;
    ASPOSE_DLL_EXPORT void fromJson(web::json::value& json) override;
    ASPOSE_DLL_EXPORT std::string toString() const override;
    ASPOSE_DLL_EXPORT void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    ASPOSE_DLL_EXPORT void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DiscUsage members

    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT int64_t getUsedSize() const;
    ASPOSE_DLL_EXPORT void setUsedSize(int64_t value);
    /// <summary>
    /// 
    /// </summary>
    ASPOSE_DLL_EXPORT int64_t getTotalSize() const;
    ASPOSE_DLL_EXPORT void setTotalSize(int64_t value);

private:
        int64_t m_UsedSize;
        int64_t m_TotalSize;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_DiscUsage_H_ */
