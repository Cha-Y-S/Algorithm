#include <iostream>
#include "solution.h"

using namespace std;

void printAnswer(vector<int> result);

int main(){
  vector<int> array;
  vector<vector<int>> commands;

  printAnswer(solution(array={1,5,2,6,3,7,4}, commands={{2,5,3},{4,4,1},{1,7,3}}));

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