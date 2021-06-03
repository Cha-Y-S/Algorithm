#include "solution.h"

void printAnswer(vector<vector<int>> result);

int main(){
  vector<vector<int>> arr1;
  vector<vector<int>> arr2;

  printAnswer(solution(arr1={{1,2},{2,3}}, arr2={{3,4},{5,6}}));

  printAnswer(solution(arr1={{1},{2}}, arr2={{3},{4}}));

  return 0;
}

void printAnswer(vector<vector<int>> result){
  for(int i = 0; i < result.size(); i++){
    if(i == 0) { cout << "["; }
    if(i + 1 == result.size()){
      for(int j = 0; j < result[i].size(); j++){
        if(j == 0) { cout << "["; }
        if(j + 1 == result[i].size()){
          cout << result[i][j] << "]";
          break;
        }
        cout << result[i][j] << ", ";
      }
      cout << "]" << endl;
      break;
    }
    for(int j = 0; j < result[i].size(); j++){
      if(j == 0) {cout << "["; }
      if(j + 1 == result[i].size()){
        cout << result[i][j] << "], ";
        break;
      }
      cout << result[i][j] << ", ";
    }
  }
  
}