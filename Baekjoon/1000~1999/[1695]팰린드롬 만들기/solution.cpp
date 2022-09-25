#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> min_value;
vector<int> arr;
int N;

void fast_io();
void init_data();
int get_min_value(int left, int right);

int main() {
  fast_io();
  init_data();

  cout << get_min_value(0, N - 1) << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void init_data() {
  cin >> N;

  arr = vector<int>(N);
  min_value = vector<vector<int>>(N, vector<int>(N, -1));

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
}

int get_min_value(int left, int right) {
  if (left >= right) return 0;
  if (min_value[left][right] != -1) return min_value[left][right];

  min_value[left][right] = 0;

  if (arr[left] == arr[right])
    min_value[left][right] += get_min_value(left + 1, right - 1);
  else
    min_value[left][right] +=
        1 + min(get_min_value(left + 1, right), get_min_value(left, right - 1));

  return min_value[left][right];
}
