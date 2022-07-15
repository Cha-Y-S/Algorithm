#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> trees;
int N, M;
ll max_h, min_h, sum, height, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  trees = vector<int>(N);
  min_h = 0;
  max_h = 0;
  sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> trees[i];
    max_h = max_h < trees[i] ? trees[i] : max_h;
  }

  while (min_h <= max_h) {
    height = (max_h + min_h) / 2;
    sum = 0;

    for (int i = 0; i < N; i++) {
      if (trees[i] - height >= 0)
        sum += trees[i] - height;
    }

    if (sum >= M) {
      res = height;
      min_h = height + 1;
    } else
      max_h = height - 1;
  }

  cout << res << endl;

  return 0;
}