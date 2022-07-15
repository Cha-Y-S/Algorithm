#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> res;
int N, seq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  res.push_back(1'000'001);

  for (int i = 0; i < N; i++) {
    cin >> seq;

    int idx = lower_bound(res.begin(), res.end(), seq) - res.begin();
    if (idx == res.size())
      res.push_back(seq);
    else
      res[idx] = seq;
  }

  cout << res.size() << endl;

  return 0;
}