#include "solution.h"

int main() {
  vector<string> table, languages;
  vector<int> preference;

  cout << solution(table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"}, languages = {"PYTHON", "C++", "SQL"}, preference = {7, 5, 5}) << endl;

  cout << solution(table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"}, languages = {"JAVA", "JAVASCRIPT"}, preference = {7, 5}) << endl;

  return 0;
}