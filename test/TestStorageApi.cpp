/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestStorageApi.cpp">
*  Copyright (c) 2019 Aspose.HTML for Cloud
* </copyright>
* <summary>
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary>
* --------------------------------------------------------------------------------------------------------------------
*/


#include "ApiConfiguration.h"
#include "api/StorageApi.h"
#include "TestBase.h"


using namespace com::aspose::api;
using namespace com::aspose::model;


class TestStorageApi : public TestBase
{

public:

    StorageApi* api;

protected:

    void SetUp()
	{
        try
        {
            std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
            std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
            api = new StorageApi(apiClient);
        }
        catch (std::exception& e)
        {
            api = nullptr;
            std::cout << e.what() << '\n';
        }
    }

    void TearDown()
    {
        if (api != nullptr) { delete api; }
    }
};

//      TEST FILE API      
TEST_F(TestStorageApi, testUploadFile)
{
    utility::string_t name = _XPLATSTR("test_download.jpg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    
    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testFileUpload.jpg");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->uploadFile(path_to_file, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());

    boost::optional<utility::string_t> versionId = _XPLATSTR("");

    // Download file from storage
    auto result_download = api->downloadFile(path_to_file, versionId, storageName).get();

    std::ofstream saved_data(testResult + _XPLATSTR("testUploadedFile.jpg"), std::ios::out | std::ios::binary);

    //Save file locally
    if (saved_data.is_open())
    {
        result_download.writeTo(saved_data);
        saved_data.close();
    }
    else
    {
        std::cout << "Unable to save downloaded file";
        ASSERT_TRUE(false);
    }

    //Delete file from storage
    auto result_delete = api->deleteFile(path_to_file, versionId, storageName).get();

    ASSERT_TRUE(result_delete->getCode() == 200);
    ASSERT_TRUE(result_delete->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestStorageApi, testDeleteFile)
{
    // Upload file to storage
    utility::string_t name = _XPLATSTR("test_download.jpg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testDeleteFile.jpg");
    boost::optional<utility::string_t> storageName = _XPLATSTR("");

    auto result = api->uploadFile(path_to_file, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());
    
    //Test delete file
	boost::optional<utility::string_t> versionId = _XPLATSTR("");

	auto result_delete = api->deleteFile(path_to_file, versionId, storageName).get();

	ASSERT_TRUE(result_delete->getCode() == 200);
	ASSERT_TRUE(result_delete->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestStorageApi, testDownloadFile)
{
	//Create file in storage
    utility::string_t name = _XPLATSTR("test.txt");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	boost::optional<utility::string_t> storageName = _XPLATSTR("");

    utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testDowmloadFile.txt");

	auto result = api->uploadFile(path_to_file, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());

	// Download file from storage
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    auto result_download = api->downloadFile(path_to_file, versionId, storageName).get();

	std::ofstream saved_data(testResult + _XPLATSTR("testDowmloadFile.txt"), std::ios::out | std::ios::binary);

	//Save file locally
	if (saved_data.is_open()) 
	{
		result_download.writeTo(saved_data);
		saved_data.close();
	}
	else
	{
		std::cout << "Unable to open file";
		ASSERT_TRUE(false);
	}

	//Clear file
	auto result_clear = api->deleteFile(path_to_file, versionId, storageName).get();
	
	ASSERT_TRUE(result_clear->getCode() == 200);
	ASSERT_TRUE(result_clear->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestStorageApi, testMoveFile)
{
	// Create file for move
    utility::string_t name = _XPLATSTR("test_for_moved.txt");
	utility::string_t srcPath = _XPLATSTR("HtmlTestDoc/test_for_moved.txt");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
    boost::optional<utility::string_t> srcStorageName = _XPLATSTR("");

    auto result = api->uploadFile(srcPath, file, srcStorageName).get();

    ASSERT_FALSE(result->errorsIsSet());

    //Move file in the storage
    utility::string_t destPath = _XPLATSTR("HtmlTestDoc/moved_file.txt");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> destStorageName = _XPLATSTR("");

    auto res_move = api->moveFile(srcPath, destPath, versionId, srcStorageName, destStorageName).get();

	ASSERT_TRUE(res_move->getCode() == 200);
	ASSERT_TRUE(res_move->getStatus() == _XPLATSTR("OK"));

	//Clear moving file
	auto result_del = api->deleteFile(destPath, versionId, destStorageName).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}

//      TEST FOLDER API      
TEST_F(TestStorageApi, testcreateFolder)
{
	// Create folder
	utility::string_t path = _XPLATSTR("HtmlTestDoc/TestFolder");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<bool> recursive = true;

	auto result = api->createFolder(path, storageName).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	//Check is folder exist
	auto result_exist = api->objectExists(path, versionId, storageName).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_TRUE(result_exist->isFolder());

	//Delete folder
	auto result_del = api->deleteFolder(path, storageName, recursive).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	//Check is folder not exist
	result_exist = api->objectExists(path, versionId, storageName).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestStorageApi, testDeleteFolderRecursive)
{
	// Create folder
	utility::string_t folder_name = _XPLATSTR("HtmlTestDoc/TestDeleteFolder");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> dest_storage = _XPLATSTR("");
	boost::optional<bool> recursive = true;

	auto result = api->createFolder(folder_name, storageName).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	//Check is folder exist
	auto result_exist = api->objectExists(folder_name, versionId, storageName).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_TRUE(result_exist->isFolder());

	//Delete folder
	auto result_del = api->deleteFolder(folder_name, storageName, recursive).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	//Check is folder not exist
	result_exist = api->objectExists(folder_name, versionId, storageName).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestStorageApi, testDeleteFolderNotRecursive)
{
    // Create folder
    utility::string_t folder_name = _XPLATSTR("HtmlTestDoc/TestDeleteFolder");
    boost::optional<utility::string_t> storageName = _XPLATSTR("");
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    boost::optional<utility::string_t> dest_storage = _XPLATSTR("");
    boost::optional<bool> recursive = false;

    auto result = api->createFolder(folder_name, storageName).get();

    ASSERT_TRUE(result->getCode() == 200);
    ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

    //Check is folder exist
    auto result_exist = api->objectExists(folder_name, versionId, storageName).get();

    ASSERT_TRUE(result_exist->isExists());
    ASSERT_TRUE(result_exist->isFolder());

    //Delete folder
    auto result_del = api->deleteFolder(folder_name, storageName, recursive).get();

    ASSERT_TRUE(result_del->getCode() == 200);
    ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

    //Check is folder not exist
    result_exist = api->objectExists(folder_name, versionId, storageName).get();

    ASSERT_FALSE(result_exist->isExists());
    ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestStorageApi, testGetListFiles)
{
	utility::string_t folder_name = _XPLATSTR("HtmlTestDoc");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->getFilesList(folder_name, storageName).get();

	std::ofstream saved_data(testResult + _XPLATSTR("file_list.json"), std::ios::out | std::ios::binary);

	//Save file locally
	if (saved_data.is_open())
	{
        utility::string_t res = result->toJson().serialize();
        saved_data << utility::conversions::to_utf8string(res);
		saved_data.close();
        ASSERT_TRUE(true);
	}
	else
	{
		std::cout << "Unable to open file";
		ASSERT_TRUE(false);
	}
}
TEST_F(TestStorageApi, testMoveFolder)
{
	utility::string_t srcPath = _XPLATSTR("TestForMoveFolder");
	utility::string_t destPath = _XPLATSTR("TestMovedFolder");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> srcStorageName = _XPLATSTR("");
	boost::optional<utility::string_t> destStorageName = _XPLATSTR("");
	boost::optional<bool> recursive = true;

	// Create folder for moving
	auto create = api->createFolder(srcPath, srcStorageName).get();

	ASSERT_TRUE(create->getCode() == 200);
	ASSERT_TRUE(create->getStatus() == _XPLATSTR("OK"));

	//Check is folder exist
	auto result_exist = api->objectExists(srcPath, versionId, srcStorageName).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_TRUE(result_exist->isFolder());

	// Moving folder
	auto move = api->moveFolder(srcPath, destPath, srcStorageName, destStorageName).get();

	ASSERT_TRUE(move->getCode() == 200);
	ASSERT_TRUE(move->getStatus() == _XPLATSTR("OK"));

	//Check is srcFolder not exist
	result_exist = api->objectExists(srcPath, versionId, srcStorageName).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	// Check is destFolder exist
	result_exist = api->objectExists(destPath, versionId, destStorageName).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_TRUE(result_exist->isFolder());

	// Delete destFolder
	auto result_del = api->deleteFolder(destPath, destStorageName, recursive).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}

//      TEST STORAGE API      
TEST_F(TestStorageApi, testGetDiskUsage)
{
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->getDiscUsage(storageName).get();

	ASSERT_TRUE(result->getTotalSize() > 0);
	ASSERT_TRUE(result->getUsedSize() > 0);
}
TEST_F(TestStorageApi, testGetIsExist)
{
	//Create file in storage
    utility::string_t name = _XPLATSTR("test.txt");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testExists.txt");

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->uploadFile(path_to_file, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());

	// Check exist file
	auto result_exist = api->objectExists(path_to_file, versionId, storageName).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	//Clear file
	auto result_del = api->deleteFile(path_to_file, versionId, storageName).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = api->objectExists(path_to_file, versionId, storageName).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestStorageApi, testGetIsStorageExistNotExist)
{
	utility::string_t storage_not_exist = _XPLATSTR("NotExistStorage");

    auto result = api->storageExists(storage_not_exist).get();
    ASSERT_FALSE(result->isExists());
}
TEST_F(TestStorageApi, testGetIsStorageExistExist)
{
    utility::string_t storage_exist = _XPLATSTR("");

    auto result = api->storageExists(storage_exist).get();
    ASSERT_TRUE(result->isExists());
}
TEST_F(TestStorageApi, testGetListFileVersion)
{
	//Create several files in storage
    utility::string_t name = _XPLATSTR("test.txt");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test.txt");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->uploadFile(path_to_file, file, storageName).get();
	ASSERT_FALSE(result->errorsIsSet());

	result = api->uploadFile(path_to_file, file, storageName).get();
    ASSERT_FALSE(result->errorsIsSet());
	
	result = api->uploadFile(path_to_file, file, storageName).get();
    ASSERT_FALSE(result->errorsIsSet());

	//Get file versions
	auto list = api->getFileVersions(path_to_file, storageName).get();

    std::ofstream saved_data(testResult + _XPLATSTR("file_list_version.json"), std::ios::out | std::ios::binary);

    //Save file locally
    if (saved_data.is_open())
    {
        utility::string_t res = list->toJson().serialize();
        saved_data << utility::conversions::to_utf8string(res);
        saved_data.close();
        ASSERT_TRUE(true);
    }
    else
    {
        std::cout << "Unable to open file";
        ASSERT_TRUE(false);
    }
}
