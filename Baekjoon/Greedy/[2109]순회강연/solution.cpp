#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define endl "\n"

priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> info;
int N, P, D, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> P >> D;

    info.push_back({D, P});
  }

  sort(info.begin(), info.end());

  for (int i = 0; i < N; i++) {
    cout << info[i].first << " " << info[i].second << endl;
  }

  for (int i = 0; i < N; i++) {
    pq.push(info[i].second);
    res += info[i].second;

    if (pq.size() > info[i].first) {
      res -= pq.top();
      pq.pop();
    }
  }

  cout << res << endl;

  return 0;
}