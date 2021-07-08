#include "solution.h"

string getAnswer(bool result);

int main() {
  cout << getAnswer(solution("()()")) << endl;

  cout << getAnswer(solution("(())()")) << endl;

  cout << getAnswer(solution(")()(")) << endl;

  cout << getAnswer(solution("(()(")) << endl;

  return 0;
}

string getAnswer(bool result) {
  return result ? "true" : "false";
}