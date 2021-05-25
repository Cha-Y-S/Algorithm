#include "solution.h"

void printAnswer(vector<int> result);

int main(){
  vector<int> arr;

  printAnswer(solution(arr={1,1,3,3,0,1,1}));

  printAnswer(solution(arr={4,4,4,3,3}));

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