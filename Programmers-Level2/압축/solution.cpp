#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;
  vector<string> voca;

  // Initialize vocabulary
  for (char i = 'A'; i <= 'Z'; i++) {
    char ch[2] = {i, '\0'};
    string str(ch);
    voca.push_back(str);
  }

  return answer;
}