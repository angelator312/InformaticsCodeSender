#include "main.hpp"
#include <cstdio>
#include <utility>
#include <vector>

// std::string
// URL_FOR_ARENA="https://arena.olimpiici.com/api/competitions/{competitionId}/problem/{canonicalCompetitionProblemId}/submit";

int main(int argc, char **argv) {
  Code code = GetCodeFromFile("test.cpp");
  printf("param1:%s;param2:%s\n", code.first.c_str(), code.second.c_str());
  if (code.type == TypeOfSite::ARENA) {
    string response =
        SendCodeToArena(code.first.c_str(), code.second.c_str(), code.code);
    string id = GetIDFromString(response);
    string url = URLFromID(id, arena::SUBMISSION_URL);
    OpenURLInBrowser(url);
  }
}

string SendCodeToArena(const char *competitionId,
                       const char *canonicalCompetitionId, string code) {
  char url[arena::SUBMIT_URL.size() + 3];
  sprintf(url, arena::SUBMIT_URL.c_str(), competitionId,
          canonicalCompetitionId);
  printf("POST %s\n", url);
  cpr::Response r =
      cpr::Post(cpr::Url(url), cpr::Bearer(arena::BEARER_TOKEN),
                cpr::Body{code}, cpr::Header{{"Content-Type", "text/plain"}});
  printf("RESPONSE: %s", r.text.c_str());
  return r.text;
}

string GetIDFromString(string s) {
  int end = s.find(',');
  s = s.substr(0, end);
  int start = s.find_last_of(':') + 1;
  s = s.substr(start);
  printf("%s\n", s.c_str());
  return s;
}

string URLFromID(const string id, string startUrl) {
  char buffer[startUrl.size() + 15];
  sprintf(buffer, startUrl.c_str(), id.c_str());
  return string(buffer);
}

void OpenURLInBrowser(const string url) {
  printf("Opening %s\n", url.c_str());
  if (OPEN_BROWSER_COMMAND.empty()) {
    printf("Can't open browser in this OS.");
    return;
  }
  system((OPEN_BROWSER_COMMAND + " " + url).c_str());
}

Code GetCodeFromFile(const string filename) {
  std::ifstream f(filename);

  // Check if the file is
  // successfully opened
  if (!f.is_open()) {
    printf("Error opening the file");
    return {};
  }
  Code out;
  string s, firstLine;

  // Read each line of the file, store
  // it in string s and print it to the
  // standard output stream
  getline(f, firstLine);
  while (getline(f, s)) {
    out.code += s;
    out.code += "\n";
  }
  if (firstLine.find(arena::ORIGIN_URL) != string::npos) {
    auto e = GetParamsForArena(firstLine);
    out.first = e.first;
    out.second = e.second;
    out.type = TypeOfSite::ARENA;
  } else {

    out.type = TypeOfSite::PESHO;
  }

  // Close the file
  f.close();
  return out;
}

std::pair<string, string> GetParamsForArena(string url) {
  std::stringstream ss(url.substr(3));
  string t;
  char del = '/';
  std::vector<string> parts;
  while (getline(ss, t, del))
    parts.push_back(t);
  return {parts[5], parts[7]};
};
