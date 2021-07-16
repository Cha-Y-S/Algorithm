#include "solution.h"

template <typename T>
void printAnswer(vector<T> result);

int main() {
  vector<string> record;

  printAnswer(solution(record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"}));

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