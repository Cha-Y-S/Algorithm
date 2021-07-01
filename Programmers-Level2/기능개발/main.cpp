#include "solution.h"

void printAnswer(vector<int> result);

int main() {
  vector<int> progresses;
  vector<int> speeds;

  printAnswer(solution(progresses = {93, 30, 55}, speeds = {1, 30, 5}));

  printAnswer(solution(progresses = {95, 90, 99, 99, 80, 99}, speeds = {1, 1, 1, 1, 1, 1}));

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