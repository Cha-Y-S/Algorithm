#include <iostream>
#include "test.h"

using namespace std;

void printAnswer(vector<int> result);

int main() {
  vector<int> answers = {1,2,3,4,5};
  vector<int> result;
  
  printAnswer(result=solution(answers));

  answers = {1,3,2,4,2};

  printAnswer(result=solution(answers));
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