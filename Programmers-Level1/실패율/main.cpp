#include "solution.h"

void printAnswer(vector<int> result);

int main() {
  vector<int> stages;

  printAnswer(solution(5, stages = {2, 1, 2, 6, 2, 4, 3, 3}));

  printAnswer(solution(4, stages = {4, 4, 4, 4, 4}));

  return 0;
}

void printAnswer(vector<int> result) {
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