#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> nums;
vector<int> sequence;
int N, M;

void combination(int idx, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  nums = vector<int>(N);
  sequence = vector<int>(M);

  for (int i = 0; i < N; i++)
    cin >> nums[i];

  sort(nums.begin(), nums.end());

  combination(0, 0);

  return 0;
}

void combination(int idx, int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << sequence[i] << " ";
    cout << endl;
    return;
  }
  for (int i = idx; i < N; i++) {
    sequence[cnt] = nums[i];
    combination(i, cnt + 1);
  }
}