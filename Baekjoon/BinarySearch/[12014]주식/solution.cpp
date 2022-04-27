#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> lis;
int T, N, K, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (int t = 0; t < T; t++) {
    cout << "Case #" << t + 1 << endl;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
      cin >> num;

      int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

      if (idx == lis.size())
        lis.push_back(num);
      else
        lis[idx] = num;
    }

    cout << (K <= lis.size() ? 1 : 0) << endl;

    lis.clear();
  }

  return 0;
}