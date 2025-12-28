#include "main.hpp"
#include <cstdio>
void SetAuth(int argc, char **argv) {
  if (argc < 3) {
    puts("Add what to authenticate");
    return;
  }
  if (argv[2][0] == 'p') {
    if (argc < 5) {
      puts("Add user and pass.");
      return;
    }
    string home = getenv("HOME");
    string path = home + PATH_TO_CONFIG;
    auto e = std::filesystem::create_directories(path);
    std::ofstream f(path + "pesho.env");
    f << argv[3] << "\n";
    f << argv[4] << "\n";
    f.close();
  } else if (argv[2][0] == 'a') {
    if (argc < 4) {
      puts("Add Bearer token");
      return;
    }
    string home = getenv("HOME");
    string path = home + PATH_TO_CONFIG;
    auto e = std::filesystem::create_directories(path);
    std::ofstream f(path + "arena.env");
    f << argv[3] << "\n";
    f.close();
  }
}
std::pair<string, string> GetPeshoAuth() {
  string home = getenv("HOME");
  std::ifstream f(home + PATH_TO_CONFIG + PESHO_CONFIG_FILENAME);
  string s, s2;
  getline(f, s, '\n');
  getline(f, s2, '\n');
  f.close();
  return {s, s2};
}

string GetArenaAuth() {
  string home = getenv("HOME");
  std::ifstream f(home + PATH_TO_CONFIG + ARENA_CONFIG_FILENAME);
  string s;
  getline(f, s, '\n');
  f.close();
  return s;
}
