#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  string answer = "";
  stringstream st;

  // To lower character only for alphabet
  for (int i = 0; i < s.size(); i++) {
    if (isalpha(s[i]) && (('A' <= s[i]) && ('Z' >= s[i]))) {
      s[i] = tolower(s[i]);
    }
  }

  if (isalpha(s[0])) {
    s[0] = toupper(s[0]);
  }

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == ' ' && (i + 1 < s.size()) && isalpha(s[i + 1])) {
      s[i + 1] = toupper(s[i + 1]);
    }
  }

  answer = s;

  return answer;
}