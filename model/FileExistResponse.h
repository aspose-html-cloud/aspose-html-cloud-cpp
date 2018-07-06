#ifndef COM_ASPOSE_MODEL_FileExistResponse_H_
#define COM_ASPOSE_MODEL_FileExistResponse_H_


#include "MessageResponse.h"
#include "FileExist.h"
#include <cpprest/details/basic_types.h>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  FileExistResponse
    : public MessageResponse
{
public:
    FileExistResponse();
    virtual ~FileExistResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileExistResponse members

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<FileExist> getFileExist() const;
    bool fileExistIsSet() const;
    void unsetFileExist();
    void setFileExist(std::shared_ptr<FileExist> value);

protected:
    std::shared_ptr<FileExist> m_FileExist;
    bool m_FileExistIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileExistResponse_H_ */
