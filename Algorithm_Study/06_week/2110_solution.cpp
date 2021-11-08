#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> house;
int N, C, low, high, mid, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> C;

  house = vector<int>(N);

  for (int i = 0; i < N; i++)
    cin >> house[i];

  sort(house.begin(), house.end());
  low = 1;
  high = house[N - 1];
  res = 0;

  while (low <= high) {
    mid = (low + high) / 2;

    int cnt = 1;
    int prev = house[0];

    for (int i = 1; i < N; i++) {
      if (house[i] - prev >= mid) {
        cnt++;
        prev = house[i];
      }
    }

    if (cnt >= C) {
      low = mid + 1;
      res = res < mid ? mid : res;
    } else
      high = mid - 1;
  }

  cout << res << endl;

  return 0;
}