#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

void fast_io();

vector<int> stuffs;
int N, M, left_point, right_point, res;

int main() {
  fast_io();

  cin >> N >> M;

  stuffs = vector<int>(N);
  res = left_point = 0;
  right_point = N - 1;

  for (int i = 0; i < N; i++) {
    cin >> stuffs[i];
  }

  sort(stuffs.begin(), stuffs.end());

  while (left_point < right_point) {
    if (stuffs[left_point] + stuffs[right_point] < M) {
      left_point++;
    } else if (stuffs[left_point] + stuffs[right_point] > M) {
      right_point--;
    } else {
      res++;
      left_point++;
    }
  }

  cout << res << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}