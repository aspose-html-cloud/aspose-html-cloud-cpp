#ifndef COM_ASPOSE_API_StorageApi_H_
#define COM_ASPOSE_API_StorageApi_H_


#include "../ApiClient.h"

#include "DiscUsageResponse.h"
#include "FileExistResponse.h"
#include "FileVersionsResponse.h"
#include "HttpContent.h"
#include "StorageExistResponse.h"
#include "MoveFileResponse.h"
#include "RemoveFileResponse.h"
#include "MoveFolderResponse.h"
#include "RemoveFolderResponse.h"
#include <cpprest/details/basic_types.h>

#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class  StorageApi
{
public:
    StorageApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~StorageApi();

    
/*    STORAGE API     */


    /// <summary>
    /// Check the disk usage of the current account 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<std::shared_ptr<DiscUsageResponse>> getDiscUsage(
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Check if a specific file or folder exists
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">File or folder path e.g. /file.ext or /Folder1</param>
    /// <param name="versionId">File&#39;s version (optional)</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<std::shared_ptr<FileExistResponse>> getIsExist(
        utility::string_t path,
        boost::optional<utility::string_t> versionId,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Check if storage exists 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="name">Storage name</param>
    pplx::task<std::shared_ptr<StorageExistResponse>> getIsStorageExist(
        utility::string_t name
    );
    /// <summary>
    /// Get the file&#39;s versions list 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">File path e.g. /file.ext or /Folder1/file.ext</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<std::shared_ptr<FileVersionsResponse>> getListFileVersions(
        utility::string_t path,
        boost::optional<utility::string_t> storage
    );

/*    FILE API     */


    /// <summary>
    /// Remove a specific file 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">Path of the file including file name and extension e.g. /Folder1/file.ext</param>
    /// <param name="versionId">File&#39;s version (optional)</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<std::shared_ptr<RemoveFileResponse>> deleteFile(
        utility::string_t path,
        boost::optional<utility::string_t> versionId,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Download a specific file 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">Path of the file including the file name and extension e.g. /file.ext</param>
    /// <param name="versionId">File&#39;s version (optional)</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<HttpContent> getDownload(
        utility::string_t path,
        boost::optional<utility::string_t> versionId,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Move a specific file 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Source file path e.g. /fileSource.ext</param>
    /// <param name="dest">Destination file path e.g. /fileDestination.ext</param>
    /// <param name="versionId">Source file&#39;s version, (optional)</param>
    /// <param name="storage">User&#39;s source storage name (optional)</param>
    /// <param name="destStorage">User&#39;s destination storage name (optional)</param>
    pplx::task<std::shared_ptr<MoveFileResponse>> postMoveFile(
        utility::string_t src,
        utility::string_t dest,
        boost::optional<utility::string_t> versionId,
        boost::optional<utility::string_t> storage,
        boost::optional<utility::string_t> destStorage
    );
    /// <summary>
    /// Upload a specific file 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext</param>
    /// <param name="file">File to upload</param>
    /// <param name="versionId">Source file&#39;s version (optional)</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<std::shared_ptr<MessageResponse>> putCreate(
        utility::string_t path,
        std::shared_ptr<HttpContent> file,
        boost::optional<utility::string_t> versionId,
        boost::optional<utility::string_t> storage
    );

    
/*    FOLDER API     */
    
    /// <summary>
    /// Remove a specific folder 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">Folder path e.g. /Folder1</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    /// <param name="recursive">Remove recursivelly inner folder/files. If false and folder contains data than exception is raised. (optional, default to false)</param>
    pplx::task<std::shared_ptr<RemoveFolderResponse>> deleteFolder(
        utility::string_t path,
        boost::optional<utility::string_t> storage,
        boost::optional<bool> recursive
    );
    /// <summary>
    /// Get the file listing of a specific folder 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">Start with name of storage e.g. root folder &#39;/&#39;or some folder &#39;/folder1/..&#39; (optional, default to /)</param>
    /// <param name="storage">User&#39;s storage name (optional)</param>
    pplx::task<HttpContent> getListFiles(
        boost::optional<utility::string_t> path,
        boost::optional<utility::string_t> storage
    );
    /// <summary>
    /// Move a specific folder 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="src">Source folder path e.g. /Folder1</param>
    /// <param name="dest">Destination folder path e.g. /Folder2</param>
    /// <param name="storage">User&#39;s source storage name (optional)</param>
    /// <param name="destStorage">User&#39;s destination storage name (optional)</param>
    pplx::task<std::shared_ptr<MoveFolderResponse>> postMoveFolder(
        utility::string_t src,
        utility::string_t dest,
        boost::optional<utility::string_t> storage,
        boost::optional<utility::string_t> destStorage
    );
    /// <summary>
    /// Create the folder 
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="path">Target folder&#39;s path e.g. Folder1/Folder2/. The folders will be created recursively</param>
    /// <param name="storage">User&#39;s source storage name (optional)</param>
    /// <param name="destStorage">User&#39;s destination storage name (optional)</param>
    pplx::task<std::shared_ptr<MessageResponse>> putCreateFolder(
        utility::string_t path,
        boost::optional<utility::string_t> storage,
        boost::optional<utility::string_t> destStorage
    );
    
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_StorageApi_H_ */

