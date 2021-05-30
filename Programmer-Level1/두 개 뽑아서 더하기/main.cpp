#include "solution.h"

void printAnswer(vector<int> result);

int main(){
  vector<int> numbers;
  printAnswer(solution(numbers={2,1,3,4,1}));

  printAnswer(solution(numbers={5,0,2,7}));
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