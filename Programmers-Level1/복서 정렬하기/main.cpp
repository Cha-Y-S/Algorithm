#include "solution.h"

template <typename T>
void printAnswer(vector<T> result);

int main() {
  vector<int> weights;
  vector<string> head2head;

  printAnswer(solution(weights = {50, 82, 75, 120}, head2head = {"NLWL", "WNLL", "LWNW", "WWLN"}));

  printAnswer(solution(weights = {145, 92, 86}, head2head = {"NLW", "WNL", "LWN"}));

  printAnswer(solution(weights = {60, 70, 60}, head2head = {"NNN", "NNN", "NNN"}));

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