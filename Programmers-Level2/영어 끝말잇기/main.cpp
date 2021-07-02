#include "solution.h"

void printAnswer(vector<int> result);

int main() {
  vector<string> words;

  printAnswer(solution(3, words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"}));

  printAnswer(solution(5, words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"}));

  printAnswer(solution(2, words = {"hello", "one", "even", "never", "now", "world", "draw"}));

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