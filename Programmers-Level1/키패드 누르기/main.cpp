#include "solution.h"

int main() {
  vector<int> numbers;
  string hand;

  cout << solution(numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, hand = "right") << endl;

  cout << solution(numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, hand = "left") << endl;

  cout << solution(numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, hand = "right") << endl;

  return 0;
}