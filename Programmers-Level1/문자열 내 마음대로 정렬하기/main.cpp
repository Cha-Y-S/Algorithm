#include "solution.h"

void printAnswer(vector<string> result);

int main(){
  vector<string> strings;

  printAnswer(solution(strings={"sun", "bed", "car"}, 1));

  printAnswer(solution(strings={"abce", "abcd", "cdx"}, 2));

  return 0;
}

void printAnswer(vector<string> result){
  for(int i = 0; i < result.size(); i++){
    if(i == 0) { cout << "["; }
    if(i + 1 == result.size()) {
      cout<< result[i] << "]" << endl;
      break;
    }
    cout << result[i] << ", ";
  }
}