#include "solution.h"

void printAnswer(vector<long long> result);

int main(){
  printAnswer(solution(2, 5));

  printAnswer(solution(4, 3));

  printAnswer(solution(-4, 2));

  return 0;
}

void printAnswer(vector<long long> result){
  for(int i = 0; i < result.size(); i++){
    if(i == 0) { cout << "["; }
    if(i + 1 == result.size()) {
      cout<< result[i] << "]" << endl;
      break;
    }
    cout << result[i] << ", ";
  }
}