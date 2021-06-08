#include "solution.h"

void printAnswer(vector<int> result);

int main() {
  printAnswer(solution(3, 12));

  printAnswer(solution(2, 5));

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