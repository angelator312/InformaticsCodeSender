#include <string>
using string = std::string;
namespace arena {
    static const string BEARER_TOKEN =
        "eyJhbGciOiJIUzUxMiJ9."
        "eyJzdWIiOiJhbmdlbGF0b3IzMTIiLCJhdXRoIjoiUk9MRV9VU0VSIiwiZXhwIjoxNzY1ODI4MT"
        "M5fQ.racA3TGlAo2JQz_"
        "1fe8tsrg7KM6MxYj8a0aIBwKTjCAkxKZpnKYJi7q4kLaILkAthxSNNshfRqZAKsjOMmWnAQ";

    static const string SUBMIT_URL =
        "https://arena.olimpiici.com/api/competitions/%s/"
        "problem/%s/submit";
    static const string SUBMISSION_URL =
        "https://arena.olimpiici.com/#/submission/%s/view";
    static const string ORIGIN_URL =
        "https://arena.olimpiici.com";
} // namespace arena

const string TEST_RESPONSE =
    "{\"id\":442908,\"verdict\":\"waiting\",\"uploadDate\":\"2025-11-16T08:10:"
    "34.712+02:00\",\"securityKey\":\"CWefBOLTYBe5pw9vPOej\",\"userId\":2423,"
    "\"competitionProblemId\":102067}";

#if __linux__
const string OPEN_BROWSER_COMMAND = "xdg-open";
#elif __APPLE__
const string OPEN_BROWSER_COMMAND = "";
#elif _WIN32
const string OPEN_BROWSER_COMMAND = "";
#else
const string OPEN_BROWSER_COMMAND = "";
#endif
