#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
  vector<int> answer;
  int cnt = 0;
  int zero = 0;

  while (s != "1") {
    // Remove '0'
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        s.erase(s.begin() + i, s.begin() + i + 1);
        i--;
        zero++;
      }
    }

    // Convert length to binary
    string temp;
    int size = s.size();
    for (int i = size; i > 0; i /= 2) {
      temp.insert(0, to_string(i % 2));
    }
    s = temp;
    cnt++;
  }

  answer = {cnt, zero};

  return answer;
}