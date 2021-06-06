#include <string>
#include <iostream>
using namespace std;

bool solution(string s){
  bool answer = true;
  int pCnt = 0;
  int yCnt = 0;

  for(int i = 0; i < s.size(); i++){
    if(tolower(s[i]) == 'p') pCnt++;
    else if(tolower(s[i]) == 'y') yCnt++;
  }

  answer = pCnt == yCnt ? true : false;

  return answer;
}