#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> points;
int N, D, W, res;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  res = 0;

  for (int i = 0; i < N; i++) {
    cin >> D >> W;

    points.push_back({D, W});
  }

  sort(points.begin(), points.end());

  for (int i = 0; i < N; i++) {
    pq.push(points[i].second);
    res += points[i].second;

    while (pq.size() > points[i].first) {
      res -= pq.top();
      pq.pop();
    }
  }

  cout << res << endl;

  return 0;
}