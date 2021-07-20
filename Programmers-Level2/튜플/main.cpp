#include "solution.h"

template <typename T>
void printAnswer(vector<T> result);

int main() {
  string s;

  printAnswer(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"));

  printAnswer(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"));

  printAnswer(solution("{{20,111},{111}}"));

  printAnswer(solution("{{123}}"));

  printAnswer(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"));

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