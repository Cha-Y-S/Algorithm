#include "solution.h"

template <typename T>
void printAnswer(vector<T> result);

int main() {
  printAnswer(solution("KAKAO"));

  printAnswer(solution("TOBEORNOTTOBEORTOBEORNOT"));

  printAnswer(solution("ABABABABABABABAB"));
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