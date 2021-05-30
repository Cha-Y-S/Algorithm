#include "solution.h"

void printAnswer(vector<int> result);

int main(){
  vector<int> arr;

  printAnswer(solution(arr={5, 9, 7, 10}, 5));

  printAnswer(solution(arr={2, 36, 1, 3}, 1));
  
  printAnswer(solution(arr={3, 2, 6}, 10));

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