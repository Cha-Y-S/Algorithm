#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
  string answer = "";

  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      answer.push_back('a' + (((s[i] + n) % 'a') % 26));
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      answer.push_back('A' + (((s[i] + n) % 'A')) % 26);
    } else {
      answer.push_back(s[i]);
      continue;
    }
  }

  return answer;
}