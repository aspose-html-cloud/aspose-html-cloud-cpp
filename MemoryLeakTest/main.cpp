#include <AsposeHtmlCloud.h>

#include <cstdio>
#include <cstdlib>

using namespace com::aspose::api;

// Credentials are never stored in the repository: get keys from
// https://dashboard.aspose.cloud (a free quota is available) and export them
// as ASPOSE_CLIENT_ID / ASPOSE_CLIENT_SECRET before running.
static utility::string_t required_env(const char* name)
{
    const char* value = std::getenv(name);
    if (value == nullptr || *value == '\0')
    {
        std::fprintf(stderr, "Missing Aspose Cloud credentials: set %s in the environment.\n", name);
        std::exit(2);
    }
    return utility::conversions::to_string_t(std::string(value));
}


int main(int argc, char* argv[])
{
    int first_snapshot = 0;


    for (int i = 0; i < 100; ++i) {

        // Get current directory
        std::string cur_dir(argv[0]);
        size_t pos = cur_dir.find_last_of("/\\");
        cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
        std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());

        const utility::string_t clientId = required_env("ASPOSE_CLIENT_ID");
        const utility::string_t clientSecret = required_env("ASPOSE_CLIENT_SECRET");
        const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
        const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

        // Create configuration for authorization
        std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

        // Create client from configuration
        std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

        // Create ConversionApi
        std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);

        // File name for conversion
        utility::string_t src = w_cur_dir + _XPLATSTR("test.html");
        utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");

        // Set options for conversion
        std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
        opts->setWidth(800)
            ->setHeight(600)
            ->setLeftMargin(10)
            ->setRightMargin(10)
            ->setTopMargin(10)
            ->setBottomMargin(10);

        //Conversion
        auto result = api->convertLocalToLocal(src, dst, opts);

        // Check the result file
        auto re = result->getFile();
        std::ifstream f(re.c_str());
        if (!f.good())
        {
            throw std::runtime_error("Conversion failed");
        }
    }

    int second_snapshot = 0;

    for (int i = 0; i < 100; ++i) {

        // Get current directory
        std::string cur_dir(argv[0]);
        size_t pos = cur_dir.find_last_of("/\\");
        cur_dir = cur_dir.substr(0, pos + 1); // Include the last slash
        std::wstring w_cur_dir(cur_dir.begin(), cur_dir.end());

        const utility::string_t clientId = required_env("ASPOSE_CLIENT_ID");
        const utility::string_t clientSecret = required_env("ASPOSE_CLIENT_SECRET");
        const utility::string_t basePath = _XPLATSTR("https://api.aspose.cloud/v4.0");
        const utility::string_t authPath = _XPLATSTR("https://api.aspose.cloud/connect/token");

        // Create configuration for authorization
        std::shared_ptr<ApiConfiguration> apiConfig(new ApiConfiguration(clientId, clientSecret, basePath, authPath));

        // Create client from configuration
        std::shared_ptr<ApiClient> apiClient(new ApiClient(apiConfig));

        // Create ConversionApi
        std::shared_ptr<ConversionApi> api = std::make_shared<ConversionApi>(apiClient);

        // File name for conversion
        utility::string_t src = w_cur_dir + _XPLATSTR("test.html");
        utility::string_t dst = w_cur_dir + _XPLATSTR("result.jpeg");

        // Set options for conversion
        std::shared_ptr<ConversionOptions> opts = std::make_shared<ConversionOptions>();
        opts->setWidth(800)
            ->setHeight(600)
            ->setLeftMargin(10)
            ->setRightMargin(10)
            ->setTopMargin(10)
            ->setBottomMargin(10);

        //Conversion
        auto result = api->convertLocalToLocal(src, dst, opts);

        // Check the result file
        auto re = result->getFile();
        std::ifstream f(re.c_str());
        if (!f.good())
        {
            throw std::runtime_error("Conversion failed");
        }
    }

    int final_snapshot = 0;
}
