#include "main.hpp"
#include <cstdio>
void SetAuth(int argc, char **argv) {
  if (argc < 3) {
    printf("Add what to authenticate");
    return;
  }
  if (argv[2][0] == 'p') {
    if (argc < 5) {
      puts("Add user and pass.");
      return;
    }
    string home = getenv("HOME");
    printf("path:%s\n", PATH_TO_CONFIG.c_str());
    auto e = std::filesystem::create_directories(PATH_TO_CONFIG);
    std::ofstream f(PATH_TO_CONFIG + "pesho.env");
    f << argv[3] << "\n";
    f << argv[4] << "\n";
    f.close();
  }
}
std::pair<string, string> GetPeshoAuth() {
  std::ifstream f(PATH_TO_CONFIG + "pesho.env");
  string s, s2;
  getline(f, s, '\n');
  getline(f, s2, '\n');
  return {s, s2};
}
