#include "solution.h"

void print_solution(vector<int> solution);

int main() {
  print_solution(solution(3, 2, 5));

  print_solution(solution(4, 7, 14));

  return 0;
}

void print_solution(vector<int> solution) {
  cout << "[";

  for (int i = 0; i < solution.size(); i++) {
    cout << solution[i];

    if (i + 1 != solution.size()) cout << ",";
  }

  cout << "]" << endl;
}