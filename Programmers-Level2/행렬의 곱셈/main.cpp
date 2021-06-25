#include "solution.h"

void printAnswer(vector<vector<int>> result);

int main() {
  vector<vector<int>> arr1;
  vector<vector<int>> arr2;

  printAnswer(solution(arr1 = {{1, 4}, {3, 2}, {4, 1}}, arr2 = {{3, 3}, {3, 3}}));

  printAnswer(solution(arr1 = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}, arr2 = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}}));

  return 0;
}

void printAnswer(vector<vector<int>> result) {
  for (int i = 0; i < result.size(); i++) {
    if (i == 0) {
      cout << "[";
    }
    if (i + 1 == result.size()) {
      for (int j = 0; j < result[i].size(); j++) {
        if (j == 0) {
          cout << "[";
        }
        if (j + 1 == result[i].size()) {
          cout << result[i][j] << "]";
          break;
        }
        cout << result[i][j] << ", ";
      }
      cout << "]" << endl;
      break;
    }
    for (int j = 0; j < result[i].size(); j++) {
      if (j == 0) {
        cout << "[";
      }
      if (j + 1 == result[i].size()) {
        cout << result[i][j] << "], ";
        break;
      }
      cout << result[i][j] << ", ";
    }
  }
}