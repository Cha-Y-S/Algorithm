#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MIN(X, Y) (X < Y) ? X : Y

vector<vector<int>> house;
vector<int> rgb;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  house = vector<vector<int>>(N);
  rgb = vector<int>(3);

  for (int i = 0; i < N; i++) {
    cin >> rgb[0] >> rgb[1] >> rgb[2];

    if (i > 0) {
      rgb[0] = (MIN(house[i - 1][1], house[i - 1][2])) + rgb[0];
      rgb[1] = (MIN(house[i - 1][0], house[i - 1][2])) + rgb[1];
      rgb[2] = (MIN(house[i - 1][0], house[i - 1][1])) + rgb[2];
    }
    house[i] = rgb;
  }

  cout << (MIN((MIN(house[N - 1][0], house[N - 1][1])), house[N - 1][2])) << endl;

  return 0;
}