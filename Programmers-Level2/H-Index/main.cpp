#include "solution.h"

int main() {
  vector<int> citations;

  cout << solution(citations = {3, 0, 6, 1, 5}) << endl;

  cout << solution(citations = {0, 1, 2, 3, 3, 3, 3, 3, 3, 4, 10, 20, 30, 40}) << endl;

  cout << solution(citations = {12, 11, 10, 9, 8, 1}) << endl;

  cout << solution(citations = {31, 66}) << endl;

  cout << solution(citations = {4, 4, 4, 5, 0, 1, 2, 3}) << endl;

  cout << solution(citations = {1, 1, 1, 1, 2, 2, 2, 3}) << endl;

  return 0;
}