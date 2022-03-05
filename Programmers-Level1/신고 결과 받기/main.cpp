#include "solution.h"

void print_solution(vector<int> res);

int main() {
  vector<string> id_list;
  vector<string> report;
  int k;

  print_solution(solution(id_list = {"muzi", "frodo", "apeach", "neo"}, report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2));

  print_solution(solution(id_list = {"con", "ryan"}, report = {"ryan con", "ryan con", "ryan con", "ryan con"}, 3));

  return 0;
}

void print_solution(vector<int> res) {
  cout << "[";
  for (int i = 0; i < res.size(); i++) {
    cout << res[i];
    if (i + 1 != res.size()) cout << ",";
  }
  cout << "]" << endl;
}