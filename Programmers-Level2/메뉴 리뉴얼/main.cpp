#include "solution.h"

template <typename T>
void printAnswer(vector<T> result);

int main() {
  vector<string> orders;
  vector<int> course;

  printAnswer(solution(orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, course = {2, 3, 4}));

  printAnswer(solution(orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, course = {2, 3, 5}));

  printAnswer(solution(orders = {"XYZ", "XWY", "WXA"}, course = {2, 3, 4}));

  return 0;
}

template <typename T>
void printAnswer(vector<T> result) {
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