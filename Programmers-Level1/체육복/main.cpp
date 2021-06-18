#include "solution.h"

int main() {
  vector<int> lost;
  vector<int> reserve;

  cout << solution(5, lost = {2, 4}, reserve = {1, 3, 5}) << endl;

  cout << solution(5, lost = {2, 4}, reserve = {3}) << endl;

  cout << solution(3, lost = {3}, reserve = {1}) << endl;

  return 0;
}