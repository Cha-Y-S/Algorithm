#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"

typedef pair<int, bool> pib;

priority_queue<pib, vector<pib>, greater<pib>> pq;
int N, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num;

    if (num == 0 && pq.empty())
      cout << 0 << endl;
    else if (num == 0 && !pq.empty()) {
      cout << (pq.top().second ? pq.top().first : pq.top().first * -1) << endl;
      pq.pop();
    } else {
      if (num < 0)
        pq.push({abs(num), false});
      else
        pq.push({num, true});
    }
  }

  return 0;
}