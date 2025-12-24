#include "auth.cpp"
string GetLastFilename() {
  string home = getenv("HOME");
  std::ifstream f(home + PATH_TO_CONFIG + PATH_TO_LAST_SAVE);
  string s;
  getline(f, s, '\n');
  f.close();
  return s;
}
void SaveLastFile(string filename) {
  string home = getenv("HOME");
  std::ofstream f(home + PATH_TO_CONFIG + PATH_TO_LAST_SAVE);
  string s = realpath(filename.c_str(), NULL);
  f << s;
  f.close();
}
