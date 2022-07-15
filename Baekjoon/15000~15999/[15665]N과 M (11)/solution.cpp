#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define endl "\n"

set<vector<int>> sequence_set;
vector<int> nums;
vector<int> sequence;
int N, M;

void permutation(int cnt);
void printSet();

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

  printSet();

  return 0;
}

void permutation(int cnt) {
  if (cnt == M) {
    sequence_set.insert(sequence);
    return;
  }
  for (int i = 0; i < N; i++) {
    sequence[cnt] = nums[i];
    permutation(cnt + 1);
  }
}

void printSet() {
  for (vector<int> v : sequence_set) {
    for (int e : v)
      cout << e << " ";
    cout << endl;
  }
}