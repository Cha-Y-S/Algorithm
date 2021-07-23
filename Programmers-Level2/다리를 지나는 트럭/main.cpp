#include "solution.h"

int main() {
  vector<int> truck_weights;

  cout << solution(2, 10, truck_weights = {7, 4, 5, 6}) << endl;

  cout << solution(100, 100, truck_weights = {10}) << endl;

  cout << solution(100, 100, truck_weights = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;

  return 0;
}