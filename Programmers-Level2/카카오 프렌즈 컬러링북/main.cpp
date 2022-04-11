#include "solution.h"

void print_solution(vector<int> res);

int main() {
  print_solution(solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}}));

  return 0;
}

void print_solution(vector<int> res) {
  cout << "[";

  for (int i = 0; i < res.size(); i++) {
    cout << res[i];

    if ((i + 1) != res.size()) cout << ", ";
  }

  cout << "]";
}