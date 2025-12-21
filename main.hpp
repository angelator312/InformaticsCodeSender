#include "constants.hpp"
#include <cpr/api.h>
#include <cpr/bearer.h>
#include <cpr/body.h>
#include <cpr/cpr.h>
#include <cpr/cprtypes.h>
#include <vector>

enum TypeOfSite { PESHO, ARENA };
struct Code {
  string code;
  TypeOfSite type;
  string first, second;
};

Code GetCodeFromFile(const string filename);
string SendCodeToArena(const char *competitionId,
                       const char *canonicalCompetitionId, string code,
                       string bearerToken);
string SendCodeToPesho(const char *assigment, const char *task, string code);
void ForPesho(int assigment, int task);
string GetIDFromString(string s);
string GetIDFromString2(string s);
string URLFromID(const string id, string startUrl);
void OpenURLInBrowser(const string url);
std::pair<string, string> GetParamsForArena(string url);
std::pair<string, string> GetParamsForPesho(string url);
void SetAuth(int argc, char **argv);
std::pair<string, string> GetPeshoAuth();
string GetArenaAuth();
