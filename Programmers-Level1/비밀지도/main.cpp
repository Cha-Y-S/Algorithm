#include "solution.h"

void printAnswer(vector<string> result);

int main() {
  vector<int> arr1;
  vector<int> arr2;

  printAnswer(solution(5, arr1 = {9, 20, 28, 18, 11}, arr2 = {30, 1, 21, 17, 28}));

  printAnswer(solution(6, arr1 = {46, 33, 33, 22, 31, 50}, arr2 = {27, 56, 19, 14, 14, 10}));

  return 0;
}

void printAnswer(vector<string> result) {
  for (int i = 0; i < result.size(); i++) {
    if (i == 0) {
      cout << "[";
    }
    if (i + 1 == result.size()) {
      cout << result[i] << "]" << endl;
      break;
    }
    cout << result[i] << ", ";
  }
}