#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;
  string sNum;

  for (int i = 0; i < s.size(); i++) {
    if (!isalpha(s[i])) {
      sNum.push_back(s[i]);
    } else {
      string temp;
      switch (s[i]) {
        case 'z':
          i += 3;
          sNum.push_back('0');
          break;
        case 'o':
          i += 2;
          sNum.push_back('1');
          break;
        case 't':
          if (s[i + 1] == 'w') {
            i += 2;
            sNum.push_back('2');
          } else {
            i += 4;
            sNum.push_back('3');
          }
          break;
        case 'f':
          if (s[i + 1] == 'o') {
            i += 3;
            sNum.push_back('4');
          } else {
            i += 3;
            sNum.push_back('5');
          }
          break;
        case 's':
          if (s[i + 1] == 'i') {
            i += 2;
            sNum.push_back('6');
          } else {
            i += 4;
            sNum.push_back('7');
          }
          break;
        case 'e':
          i += 4;
          sNum.push_back('8');
          break;
        case 'n':
          i += 3;
          sNum.push_back('9');
          break;
      }
    }
  }

  answer = stoi(sNum);

  return answer;
}