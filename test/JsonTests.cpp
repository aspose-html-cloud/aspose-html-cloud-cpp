/**
* --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="JsonTests.cpp">
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


using namespace com::aspose::model;


class JsonTests : public TestBase
{

protected:

    void SetUp()
    {
    }

    void TearDown()
    {
    }
};

TEST_F(JsonTests, /*DISABLED_*/testSerializeConversionOptions)
{
    ConversionOptions *opts = new ConversionOptions();

    std::string str = opts->toString();
    ASSERT_TRUE(str == "{}");
    opts->setWidth(800)->setHeight(1000)->setLeftMargin(10)->setRightMargin(20)->setTopMargin(30)->setBottomMargin(40);


    std::string str1 = opts->toString();
    ASSERT_TRUE(str1 == "{\"bottommargin\":40,\"height\":1000,\"leftmargin\":10,\"rightmargin\":20,\"topmargin\":30,\"width\":800}");
}

TEST_F(JsonTests, /*DISABLED_*/testSerializeConversionRequest)
{
    std::shared_ptr<ConversionRequest> req(new ConversionRequest());

    utility::string_t inputPath = _XPLATSTR("input_path");
    utility::string_t outputFile = _XPLATSTR("output_file");


    req->setInputPath(inputPath)->setOutputFile(outputFile);

    std::shared_ptr<ConversionOptions> opts(new ConversionOptions());
    opts->setWidth(800)->setHeight(1000)->setLeftMargin(10)->setRightMargin(20)->setTopMargin(30)->setBottomMargin(40);

    req->setOptions(opts);

    std::string str1 = req->toString();
    ASSERT_EQ(str1, "{\"InputPath\":\"input_path\",\"Options\":{\"bottommargin\":40,\"height\":1000,\"leftmargin\":10,\"rightmargin\":20,\"topmargin\":30,\"width\":800},\"OutputFile\":\"output_file\"}");

}