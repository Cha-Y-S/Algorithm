#include "solution.h"

void printAnswer(vector<int> result);

int main() {
  vector<int> lottos, win_nums;

  printAnswer(solution(lottos = {44, 1, 0, 0, 31, 25}, win_nums = {31, 10, 45, 1, 6, 19}));

  printAnswer(solution(lottos = {0, 0, 0, 0, 0, 0}, win_nums = {38, 19, 20, 40, 15, 25}));

  printAnswer(solution(lottos = {45, 4, 35, 20, 3, 9}, win_nums = {20, 9, 3, 45, 4, 35}));

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