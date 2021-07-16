#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;

  answer = s.size();

  for (int i = 1; i <= s.size() / 2; i++) {
    string temp;
    vector<string> split;

    // Get vector that has i lengh of substrings
    for (int j = 0; j < s.size(); j += i) {
      split.push_back(s.substr(j, i));
    }

    // Compress String
    int cnt = 1;
    for (int j = 1; j < split.size(); j++) {
      if (split[j - 1] == split[j]) {
        cnt++;
      } else {
        temp = cnt == 1 ? temp + split[j - 1] : temp + to_string(cnt) + split[j - 1];
        cnt = 1;
      }
    }
    temp = cnt == 1 ? temp + split[split.size() - 1] : temp + to_string(cnt) + split[split.size() - 1];

    // Set answer
    answer = answer > temp.size() ? temp.size() : answer;
  }

  return answer;
}