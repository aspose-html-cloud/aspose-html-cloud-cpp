/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestStorageApi.cpp">
*  Copyright (c) 2018 Aspose.HTML for Cloud
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


#include "pch.h"
#include "TestBase.h"
#include "ApiConfiguration.h"
#include "api/StorageApi.h"


using namespace com::aspose::api;
using namespace com::aspose::model;


class TestStorageApi : public TestBase
{
protected:
	void SetUp() 
	{
		std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));
		std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));
		api = new StorageApi(apiClient);
	}

	void TearDown() 
	{
		delete api;
	}

	StorageApi *api;

};

//      TEST FILE API      

TEST_F(TestStorageApi, testPutCreate)
{
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testPutCreate.html");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test.html"), std::ifstream::binary));
	file->setData(if_stream);

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));
}

TEST_F(TestStorageApi, testDeleteFile)
{
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/testPutCreate.html");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));
}

TEST_F(TestStorageApi, testGetDownload)
{
	//Create file in storage
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test.txt");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test.txt"), std::ifstream::binary));
	file->setData(if_stream);

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	// Download file from storage
	auto result_download = api->getDownload(path_to_file, versionId, storage).get();

	std::ofstream saved_data(testResult + _XPLATSTR("test.txt"), std::ios::out | std::ios::binary);

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
	auto result_clear = api->deleteFile(path_to_file, versionId, storage).get();
	
	ASSERT_TRUE(result_clear->getCode() == 200);
	ASSERT_TRUE(result_clear->getStatus() == _XPLATSTR("OK"));
}

TEST_F(TestStorageApi, testPostMoveFile)
{
	// Create file for move
	utility::string_t src = _XPLATSTR("HtmlTestDoc/test_for_moved.txt");
	utility::string_t dest = _XPLATSTR("HtmlTestDoc/moved_file.txt");

	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test_for_moved.txt"), std::ifstream::binary));
	file->setData(if_stream);

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");
	boost::optional<utility::string_t> dest_storage = _XPLATSTR("");

	auto result = api->putCreate(src, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	//Moving file

	auto res_move = api->postMoveFile(src, dest, versionId, storage, dest_storage).get();

	ASSERT_TRUE(res_move->getCode() == 200);
	ASSERT_TRUE(res_move->getStatus() == _XPLATSTR("OK"));

	//Clear moving file

	auto result_del = api->deleteFile(dest, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));
}


//      TEST FOLDER API      

TEST_F(TestStorageApi, putCreateFolder)
{
	// Create folder
	utility::string_t folder_name = _XPLATSTR("HtmlTestDoc/TestFolder");
	boost::optional<utility::string_t> storage = _XPLATSTR("");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> dest_storage = _XPLATSTR("");
	boost::optional<bool> recursive = true;

	auto result = api->putCreateFolder(folder_name, storage, dest_storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	//Check is folder exist
	auto result_exist = api->getIsExist(folder_name, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_TRUE(result_exist->getFileExist()->isFolder());

	//Delete folder
	auto result_del = api->deleteFolder(folder_name, storage, recursive).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	//Check is folder not exist
	result_exist = api->getIsExist(folder_name, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());
}


TEST_F(TestStorageApi, testDeleteFolder)
{
	// Create folder
	utility::string_t folder_name = _XPLATSTR("HtmlTestDoc/TestDeleteFolder");
	boost::optional<utility::string_t> storage = _XPLATSTR("");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> dest_storage = _XPLATSTR("");
	boost::optional<bool> recursive = true;

	auto result = api->putCreateFolder(folder_name, storage, dest_storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	//Check is folder exist
	auto result_exist = api->getIsExist(folder_name, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_TRUE(result_exist->getFileExist()->isFolder());

	//Delete folder
	auto result_del = api->deleteFolder(folder_name, storage, recursive).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	//Check is folder not exist
	result_exist = api->getIsExist(folder_name, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());
}


TEST_F(TestStorageApi, testGetListFiles)
{
	boost::optional<utility::string_t> folder_name = _XPLATSTR("HtmlTestDoc");
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->getListFiles(folder_name, storage).get();

	std::ofstream saved_data(testResult + _XPLATSTR("file_list.json"), std::ios::out | std::ios::binary);

	//Save file locally
	if (saved_data.is_open())
	{
		result.writeTo(saved_data);
		saved_data.close();
	}
	else
	{
		std::cout << "Unable to open file";
		ASSERT_TRUE(false);
	}

}

TEST_F(TestStorageApi, testPostMoveFolder)
{
	utility::string_t src_folder = _XPLATSTR("TestFolderForMove");
	utility::string_t dst_folder = _XPLATSTR("MovedFolder");
	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");
	boost::optional<utility::string_t> dest_storage = _XPLATSTR("");
	boost::optional<bool> recursive = true;


	// Create folder for moving
	auto create = api->putCreateFolder(src_folder, storage, dest_storage).get();

	ASSERT_TRUE(create->getCode() == 200);
	ASSERT_TRUE(create->getStatus() == _XPLATSTR("OK"));

	//Check is folder exist
	auto result_exist = api->getIsExist(src_folder, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_TRUE(result_exist->getFileExist()->isFolder());


	// Moving folder
	auto move = api->postMoveFolder(src_folder, dst_folder, storage, dest_storage).get();

	ASSERT_TRUE(move->getCode() == 200);
	ASSERT_TRUE(move->getStatus() == _XPLATSTR("OK"));


	//Check is src_folder not exist
	result_exist = api->getIsExist(src_folder, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());


	// Check is dst folder exist
	result_exist = api->getIsExist(dst_folder, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_TRUE(result_exist->getFileExist()->isFolder());

	// Delete dst folder
	auto result_del = api->deleteFolder(dst_folder, storage, recursive).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

}


//      TEST STORAGE API      

TEST_F(TestStorageApi, testGetDiskUsage)
{
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->getDiscUsage(storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result->getDiscUsage()->getTotalSize() > 0);
	ASSERT_TRUE(result->getDiscUsage()->getUsedSize() > 0);
}

TEST_F(TestStorageApi, getIsExist)
{
	//Create file in storage
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test.txt");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test.txt"), std::ifstream::binary));
	file->setData(if_stream);

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	// Check exist file
	auto result_exist = api->getIsExist(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_TRUE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());

	//Clear file
	auto result_del = api->deleteFile(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_del->getCode() == 200);
	ASSERT_TRUE(result_del->getStatus() == _XPLATSTR("OK"));

	// Check not exist file
	result_exist = api->getIsExist(path_to_file, versionId, storage).get();

	ASSERT_TRUE(result_exist->getCode() == 200);
	ASSERT_TRUE(result_exist->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result_exist->getFileExist()->isExist());
	ASSERT_FALSE(result_exist->getFileExist()->isFolder());
}

TEST_F(TestStorageApi, getIsStorageExist)
{
	utility::string_t storage_exist = _XPLATSTR("");
	utility::string_t storage_not_exist = _XPLATSTR("NotExistStorage");

	auto result = api->getIsStorageExist(storage_exist).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result->isExist());

	result = api->getIsStorageExist(storage_not_exist).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	ASSERT_FALSE(result->isExist());
}

TEST_F(TestStorageApi, getListFileVersion)
{
	//Create several files in storage
	utility::string_t path_to_file = _XPLATSTR("HtmlTestDoc/test.txt");
	std::shared_ptr<HttpContent> file(new HttpContent());
	std::shared_ptr<std::ifstream> if_stream(new std::ifstream(testSource + _XPLATSTR("test.txt"), std::ifstream::binary));
	file->setData(if_stream);

	boost::optional<utility::string_t> versionId = _XPLATSTR("");
	boost::optional<utility::string_t> storage = _XPLATSTR("");

	auto result = api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	result = api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));
	
	result = api->putCreate(path_to_file, file, versionId, storage).get();

	ASSERT_TRUE(result->getCode() == 200);
	ASSERT_TRUE(result->getStatus() == _XPLATSTR("OK"));

	//Get file versions
	auto list = api->getListFileVersions(path_to_file, storage).get();

	ASSERT_TRUE(list->getCode() == 200);
	ASSERT_TRUE(list->getStatus() == _XPLATSTR("OK"));

	std::wcout << list->toJson().serialize();
}


