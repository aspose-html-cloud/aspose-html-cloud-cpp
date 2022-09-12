/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestStorageApi.cpp">
*  Copyright (c) 2022 Aspose.HTML for Cloud
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
TEST_F(TestStorageApi, /*DISABLED_*/testUploadFile)
{
    const utility::string_t name = _XPLATSTR("test_download.jpg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
	auto path = testSource + name;
	std::ifstream f(path.c_str());
	ASSERT_TRUE(f.good());
    
    utility::string_t folder = _XPLATSTR("HtmlTestDoc");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->uploadFile(folder, file, storageName).get();
	
    ASSERT_FALSE(result->errorsIsSet());

	ASSERT_TRUE(result->getUploaded().size() > 0);
	ASSERT_TRUE(result->getErrors().size() == 0);

    boost::optional<utility::string_t> versionId = _XPLATSTR("");

    // Download file from storage
    auto result_download = api->downloadFile(folder + _XPLATSTR("/") + name, versionId, storageName).get();

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
    auto result_delete = api->deleteFile(folder + _XPLATSTR("/") + name, versionId, storageName).get();

    ASSERT_TRUE(result_delete->getCode() == 200);
    ASSERT_TRUE(result_delete->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestStorageApi, /*DISABLED_*/testDeleteFile)
{
    // Upload file to storage
    utility::string_t name = _XPLATSTR("test_download.jpg");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

    utility::string_t folder = _XPLATSTR("HtmlTestDoc");
    boost::optional<utility::string_t> storageName = _XPLATSTR("");

    auto result = api->uploadFile(folder, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());
    
    //Test delete file
	boost::optional<utility::string_t> versionId = _XPLATSTR("");

	auto result_delete = api->deleteFile(folder + _XPLATSTR("/") + name, versionId, storageName).get();

	ASSERT_TRUE(result_delete->getCode() == 200);
	ASSERT_TRUE(result_delete->getStatus() == _XPLATSTR("OK"));
}
TEST_F(TestStorageApi, /*DISABLED_*/testDownloadFile)
{
	//Create file in storage
    utility::string_t name = _XPLATSTR("test.txt");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));

	boost::optional<utility::string_t> storageName = _XPLATSTR("");

    utility::string_t folder = _XPLATSTR("HtmlTestDoc");

	auto result = api->uploadFile(folder, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());

	// Download file from storage
    boost::optional<utility::string_t> versionId = _XPLATSTR("");
    auto result_download = api->downloadFile(folder + _XPLATSTR("/") + name, versionId, storageName).get();

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
	auto result_clear = api->deleteFile(folder + _XPLATSTR("/") + name, versionId, storageName).get();
	
	ASSERT_TRUE(result_clear->getCode() == 200);
	ASSERT_TRUE(result_clear->getStatus() == _XPLATSTR("OK"));
}

//      TEST FOLDER API      
TEST_F(TestStorageApi, /*DISABLED_*/testcreateFolder)
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
TEST_F(TestStorageApi, /*DISABLED_*/testDeleteFolderRecursive)
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
TEST_F(TestStorageApi, /*DISABLED_*/testDeleteFolderNotRecursive)
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
TEST_F(TestStorageApi, /*DISABLED_*/testGetListFiles)
{
	utility::string_t folder_name = _XPLATSTR("HtmlTestDoc");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->getFilesList(folder_name, storageName).get();

	std::ofstream saved_data(testResult + _XPLATSTR("file_list.json"), std::ios::out | std::ios::binary);

	//Save file locally
	if (saved_data.is_open())
	{
        saved_data << result->toString();
		saved_data.close();
        ASSERT_TRUE(true);
	}
	else
	{
		std::cout << "Unable to open file";
		ASSERT_TRUE(false);
	}
}

//      TEST STORAGE API      
TEST_F(TestStorageApi, /*DISABLED_*/testGetDiskUsage)
{
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->getDiscUsage(storageName).get();

	ASSERT_TRUE(result->getTotalSize() > 0);
	ASSERT_TRUE(result->getUsedSize() > 0);
}
TEST_F(TestStorageApi, /*DISABLED_*/testGetIsExist)
{
	//Create file in storage
    utility::string_t name = _XPLATSTR("test.txt");
    std::shared_ptr<HttpContent> file(new HttpContent(testSource, name));
	utility::string_t folder = _XPLATSTR("HtmlTestDoc");

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storageName = _XPLATSTR("");

	auto result = api->uploadFile(folder, file, storageName).get();

    ASSERT_FALSE(result->errorsIsSet());

	// Check exist file
	auto result_exist = api->objectExists(folder + _XPLATSTR("/") + name, versionId, storageName).get();

	ASSERT_TRUE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());

	//Clear file
	auto result_del = api->deleteFile(folder + _XPLATSTR("/") + name, versionId, storageName).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = api->objectExists(folder + _XPLATSTR("/") + name, versionId, storageName).get();

	ASSERT_FALSE(result_exist->isExists());
	ASSERT_FALSE(result_exist->isFolder());
}
TEST_F(TestStorageApi, /*DISABLED_*/testGetIsStorageExistNotExist)
{
	utility::string_t storage_not_exist = _XPLATSTR("NotExistStorage");

    auto result = api->storageExists(storage_not_exist).get();
    ASSERT_FALSE(result->isExists());
}
