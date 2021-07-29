#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  cin >> n;

  vector<vector<int>> house;

  for (int i = 0; i < n; i++) {
    vector<int> input(3, 0);
    cin >> input[0] >> input[1] >> input[2];

    if (i > 0) {
      input[0] = min(house[i - 1][1], house[i - 1][2]) + input[0];
      input[1] = min(house[i - 1][0], house[i - 1][2]) + input[1];
      input[2] = min(house[i - 1][0], house[i - 1][1]) + input[2];
      house.push_back(input);
    } else {
      house.push_back(input);
    }
  }

  cout << min(min(house[n - 1][0], house[n - 1][1]), house[n - 1][2]) << endl;

  return 0;
}