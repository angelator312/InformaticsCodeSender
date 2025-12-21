#include <cpr/auth.h>
#include <string>
using string = std::string;
namespace arena {
    static const string SUBMIT_URL =
        "https://arena.olimpiici.com/api/competitions/%s/"
        "problem/%s/submit";
    static const string SUBMISSION_URL =
        "https://arena.olimpiici.com/#/submission/%s/view";
    static const string ORIGIN_URL =
        "https://arena.olimpiici.com";
    static const string CONFIG_FILENAME = "arena.env";
} // namespace arena

namespace pesho {
    static const string SUBMIT_URL = "https://pesho.org/api/user/assignments/"
                                    "%s/tasks/%s/submitcode";
    static const string SUBMISSION_URL =
        "https://pesho.org/assignments/%s/submissions/%s";
    static const string CONFIG_FILENAME = "pesho.env";
} // namespace pesho

const string TEST_RESPONSE2 = "{\n  \"id\" : 560942\n}";
const string TEST_RESPONSE =
    "{\"id\":442908,\"verdict\":\"waiting\",\"uploadDate\":\"2025-11-16T08:10:"
    "34.712+02:00\",\"securityKey\":\"CWefBOLTYBe5pw9vPOej\",\"userId\":2423,"
    "\"competitionProblemId\":102067}";


const string PATH_TO_CONFIG="/.config/CodeSenderData/";

#if __linux__
const string OPEN_BROWSER_COMMAND = "xdg-open";
#elif __APPLE__
const string OPEN_BROWSER_COMMAND = "";
#elif _WIN32
const string OPEN_BROWSER_COMMAND = "";
#else
const string OPEN_BROWSER_COMMAND = "";
#endif
