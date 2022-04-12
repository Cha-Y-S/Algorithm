#include "solution.h"

void print_solution(vector<int> res);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  print_solution(solution({180, 5000, 10, 600}, {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"}));

  print_solution(solution({120, 0, 60, 591}, {"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"}));

  print_solution(solution({1, 461, 1, 10}, {"00:00 1234 IN"}));

  return 0;
}

void print_solution(vector<int> res) {
  cout << "[";

  for (int i = 0; i < res.size(); i++) {
    cout << res[i];

    if ((i + 1) != res.size()) cout << ", ";
  }

  cout << "]" << endl;
}