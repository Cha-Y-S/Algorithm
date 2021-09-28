#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, bool> pib;

vector<int> nums;
vector<int> sequence;
int N, M;

void permutation(int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  nums = vector<int>(N);
  sequence = vector<int>(M);

  for (int i = 0; i < N; i++)
    cin >> nums[i];

  sort(nums.begin(), nums.end());

  permutation(0);

  return 0;
}

void permutation(int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << sequence[i] << " ";
    cout << endl;
    return;
  }
  for (int i = 0; i < N; i++) {
    sequence[cnt] = nums[i];
    permutation(cnt + 1);
  }
}