#ifndef COM_ASPOSE_API_StorageApi_H_
#define COM_ASPOSE_API_StorageApi_H_


#include "ApiClient.h"
#include "HttpContent.h"
#include "model/FilesUploadResult.h"
#include "model/DiscUsage.h"
#include "model/ObjectExist.h"
#include "model/FileVersions.h"
#include "model/FilesList.h"
#include "model/StorageExist.h"
#include "model/MessageResponse.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>

namespace com {
namespace aspose {
namespace api {

using namespace com::aspose::model;

class StorageApi
{
public:
    ASPOSE_DLL_EXPORT StorageApi( std::shared_ptr<ApiClient> apiClient );
    ASPOSE_DLL_EXPORT ~StorageApi();
    /// <summary>
    /// Check the disk usage of the current account.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="storageName">User's storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<DiscUsage>> getDiscUsage(
        boost::optional<utility::string_t> storageName = boost::none
    );
    /// <summary>
    /// Check if a specific file or folder exists.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">File or folder path e.g. /file.ext or /Folder1</param>
    /// <param name="versionId">File's version (optional)</param>
    /// <param name="storageName">User's storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<ObjectExist>> objectExists(
        const utility::string_t& path,
        boost::optional<utility::string_t> versionId = boost::none,
        boost::optional<utility::string_t> storageName = boost::none
    );
    /// <summary>
    /// Check if storage exists.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="storageName">Storage name</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<StorageExist>> storageExists(
        const utility::string_t& storageName
    );
    /// <summary>
    /// Remove a specific file.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">Path of the file including file name and extension e.g. /Folder1/file.ext</param>
    /// <param name="versionId">File's version (optional)</param>
    /// <param name="storageName">User's storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> deleteFile(
        const  utility::string_t& path,
        boost::optional<utility::string_t> versionId = boost::none,
        boost::optional<utility::string_t> storageName = boost::none
    );
    /// <summary>
    /// Download a specific file.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">Path of the file including the file name and extension e.g. /file.ext</param>
    /// <param name="versionId">File's version (optional)</param>
    /// <param name="storageName">User's storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<HttpContent> downloadFile(
        const utility::string_t& path,
        boost::optional<utility::string_t> versionId = boost::none,
        boost::optional<utility::string_t> storageName = boost::none
    );

    /// <summary>
    /// Upload a specific file.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">Path where to upload excluding filename e.g. / or /Folder1 </param>
    /// <param name="file">File to upload</param>
    /// <param name="storageName">User's storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<FilesUploadResult>> uploadFile(
        const utility::string_t& path,
        std::shared_ptr<HttpContent> file,
        boost::optional<utility::string_t> storageName = boost::none
    );
    /// <summary>
    /// Remove a specific folder.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">Folder path e.g. /Folder1</param>
    /// <param name="storageName">User's storage name (optional)</param>
    /// <param name="recursive">Remove recursivelly inner folder/files. If false and folder contains data than exception is raised. (optional, default to false)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> deleteFolder(
        const utility::string_t& path,
        boost::optional<utility::string_t> storageName = boost::none,
        boost::optional<bool> recursive = boost::none
    );
    /// <summary>
    /// Get all files and folders within a folder.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">Folder path e.g. '/folder'</param>
    /// <param name="storageName">Storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<FilesList>> getFilesList(
        const utility::string_t& path,
        boost::optional<utility::string_t> storageName = boost::none
    );

    /// <summary>
    /// Create the folder.
    /// </summary>
    /// <remarks>
    ///
    /// </remarks>
    /// <param name="path">Target folder's path e.g. Folder1/Folder2/. The folders will be created recursively</param>
    /// <param name="storageName">User's source storage name (optional)</param>
    ASPOSE_DLL_EXPORT pplx::task<std::shared_ptr<MessageResponse>> createFolder(
        const utility::string_t& path,
        boost::optional<utility::string_t> storageName = boost::none
    );
    
    
private:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* COM_ASPOSE_API_StorageApi_H_ */

