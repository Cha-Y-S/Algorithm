#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  cin >> n;

  vector<pair<int, int>> person(n, make_pair(0, 0));
  vector<int> grade(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> person[i].first >> person[i].second;
  }

  for (int i = 0; i < n; i++) {
    int x = person[i].first;
    int y = person[i].second;
    int k = 1;
    for (int j = 0; j < n; j++) {
      int p = person[j].first;
      int q = person[j].second;

      if (p > x && q > y) k++;
    }

    grade[i] = k;
  }

  for (int i = 0; i < n; i++) {
    cout << grade[i] << " ";
  }
  cout << endl;

  return 0;
}