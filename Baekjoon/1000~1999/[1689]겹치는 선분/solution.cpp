#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> arr;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  res = 1;

  arr = vector<pii>(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr.begin(), arr.end());

  pq.push(arr[0].second);

  for (int i = 1; i < N; i++) {
    int sp = arr[i].first;
    int ep = arr[i].second;

    while (!pq.empty() && pq.top() <= sp) {
      pq.pop();
    }

    pq.push(ep);

    res = max(res, (int)pq.size());
  }

  cout << res << endl;

  return 0;
}