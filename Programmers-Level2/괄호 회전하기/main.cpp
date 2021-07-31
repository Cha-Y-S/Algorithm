#include "solution.h"

int main() {
  cout << solution("[](){}") << endl;

  cout << solution("}]()[{") << endl;

  cout << solution("[)(]") << endl;

  cout << solution("}}}") << endl;

  return 0;
}