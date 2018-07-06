#ifndef COM_ASPOSE_MODEL_DiscUsage_H_
#define COM_ASPOSE_MODEL_DiscUsage_H_


#include "../ModelBase.h"


namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  DiscUsage
    : public ModelBase
{
public:
    DiscUsage();
    virtual ~DiscUsage();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DiscUsage members

    /// <summary>
    /// 
    /// </summary>
    int64_t getUsedSize() const;
    void setUsedSize(int64_t value);
    /// <summary>
    /// 
    /// </summary>
    int64_t getTotalSize() const;
    void setTotalSize(int64_t value);

protected:
    int64_t m_UsedSize;
        int64_t m_TotalSize;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_DiscUsage_H_ */
