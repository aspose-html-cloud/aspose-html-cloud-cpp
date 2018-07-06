#ifndef COM_ASPOSE_MODEL_FileVersionsResponse_H_
#define COM_ASPOSE_MODEL_FileVersionsResponse_H_


#include "MessageResponse.h"
#include "FileVersion.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  FileVersionsResponse
    : public MessageResponse
{
public:
    FileVersionsResponse();
    virtual ~FileVersionsResponse();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileVersionsResponse members

    /// <summary>
    /// 
    /// </summary>
    std::vector<std::shared_ptr<FileVersion>>& getFileVersions();
    bool fileVersionsIsSet() const;
    void unsetFileVersions();
    void setFileVersions(std::vector<std::shared_ptr<FileVersion>> value);

protected:
    std::vector<std::shared_ptr<FileVersion>> m_FileVersions;
    bool m_FileVersionsIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileVersionsResponse_H_ */
