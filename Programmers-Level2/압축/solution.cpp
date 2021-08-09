#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInVoca(vector<string> voca, string s);
int getVocaIndex(vector<string> voca, string s);

vector<int> solution(string msg) {
  vector<int> answer;
  vector<string> voca;

  // Initialize vocabulary
  for (char i = 'A'; i <= 'Z'; i++) {
    char ch[2] = {i, '\0'};
    string str(ch);
    voca.push_back(str);
  }
  string current, before;

  for (int i = 0; i < msg.size(); i++) {
    current = "";
    before = "";
    for (int j = i; j <= msg.size() - 1; j++) {
      current = msg.substr(i, msg.size() - j);
      // Search that is current string in vaca
      if (isInVoca(voca, current)) {
        answer.push_back(getVocaIndex(voca, current) + 1);
        // Remove current input
        i += msg.size() - j - 1;
        break;
      } else {
        // Initialize next string that was not proceeded
        before = current;
        continue;
      }
    }
    // Register next word into the voca
    if (before != "") voca.push_back(before);
  }

  return answer;
}

bool isInVoca(vector<string> voca, string s) {
  bool result = false;
  for (int i = 0; i < voca.size(); i++) {
    if (voca[i] == s) {
      result = true;
      break;
    }
  }
  return result;
}

int getVocaIndex(vector<string> voca, string s) {
  int result = 0;
  for (int i = 0; i < voca.size(); i++) {
    if (voca[i] == s) {
      result = i;
      break;
    }
  }
  return result;
}