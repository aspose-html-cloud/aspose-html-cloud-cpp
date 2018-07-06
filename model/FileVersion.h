#ifndef COM_ASPOSE_MODEL_FileVersion_H_
#define COM_ASPOSE_MODEL_FileVersion_H_


#include <cpprest/details/basic_types.h>
#include "File.h"

namespace com {
namespace aspose {
namespace model {

/// <summary>
/// 
/// </summary>
class  FileVersion
    : public File
{
public:
    FileVersion();
    virtual ~FileVersion();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FileVersion members

    /// <summary>
    /// 
    /// </summary>
    utility::string_t getVersionId() const;
    bool versionIdIsSet() const;
    void unsetVersionId();
    void setVersionId(utility::string_t value);
    /// <summary>
    /// 
    /// </summary>
    bool isIsLatest() const;
    bool isLatestIsSet() const;
    void unsetIsLatest();
    void setIsLatest(bool value);

protected:
    utility::string_t m_VersionId;
    bool m_VersionIdIsSet;
    bool m_IsLatest;
    bool m_IsLatestIsSet;
};

}
}
}

#endif /* COM_ASPOSE_MODEL_FileVersion_H_ */
