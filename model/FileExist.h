#ifndef COM_ASPOSE_MODEL_FileExist_H_
#define COM_ASPOSE_MODEL_FileExist_H_


#include "../ModelBase.h"


namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  FileExist
    : public ModelBase
{
public:
    FileExist();
    virtual ~FileExist();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileExist members

    /// <summary>
    /// 
    /// </summary>
    bool isExist() const;
    void setIsExist(bool value);
    /// <summary>
    /// 
    /// </summary>
    bool isFolder() const;
    void setIsFolder(bool value);

protected:
    bool m_IsExist;
    bool m_IsFolder;
    };

}
}
}

#endif /* COM_ASPOSE_MODEL_FileExist_H_ */
