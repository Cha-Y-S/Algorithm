#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, k, n;

  // Initialize apartment's population
  vector<vector<int>> apartment;

  apartment.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14});

  for (int i = 0; i < 14; i++) {
    vector<int> floor;

    for (int j = 0; j < 14; j++) {
      int sum = 0;
      for (int k = 0; k < j + 1; k++)
        sum += apartment[i][k];
      floor.push_back(sum);
    }
    apartment.push_back(floor);
  }

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> k >> n;

    cout << apartment[k][n - 1] << endl;
  }

  return 0;
}