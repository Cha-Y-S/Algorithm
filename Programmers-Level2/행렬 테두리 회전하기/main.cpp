#include "solution.h"

template <typename T>
void printAnswer(vector<T> result);

int main() {
  vector<vector<int>> queries;

  printAnswer(solution(6, 6, queries = {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}));

  printAnswer(solution(3, 3, queries = {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}}));

  printAnswer(solution(100, 97, queries = {{1, 1, 100, 97}}));

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