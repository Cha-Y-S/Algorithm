#include "solution.h"

void printAnswer(vector<int> result);

int main(){
  vector<int> arr;

  printAnswer(solution(arr={4,3,2,1}));

  printAnswer(solution(arr={10}));

  return 0;
}

void printAnswer(vector<int> result){
  for(int i = 0; i < result.size(); i++){
    if(i == 0) { cout << "["; }
    if(i + 1 == result.size()) {
      cout<< result[i] << "]" << endl;
      break;
    }
    cout << result[i] << ", ";
  }
}