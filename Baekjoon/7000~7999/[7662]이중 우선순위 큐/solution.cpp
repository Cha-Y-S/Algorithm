#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define endl "\n"

priority_queue<int> desc;
priority_queue<int, vector<int>, greater<int>> asc;
map<int, int> m;
char Q;
int T, K, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> K;

    for (int i = 0; i < K; i++) {
      cin >> Q >> N;

      if (Q == 'I') {
        desc.push(N);
        asc.push(N);
        m[N]++;
      } else if (N == 1) {
        while (!desc.empty() && m[desc.top()] == 0)
          desc.pop();

        if (!desc.empty()) {
          m[desc.top()]--;
          desc.pop();
        }
      } else {
        while (!asc.empty() && m[asc.top()] == 0)
          asc.pop();

        if (!asc.empty()) {
          m[asc.top()]--;
          asc.pop();
        }
      }
    }
    while (!desc.empty() && m[desc.top()] == 0)
      desc.pop();

    while (!asc.empty() && m[asc.top()] == 0)
      asc.pop();

    if (desc.empty() && asc.empty())
      cout << "EMPTY" << endl;
    else
      cout << desc.top() << " " << asc.top() << endl;

    desc = priority_queue<int>();
    asc = priority_queue<int, vector<int>, greater<int>>();
    m.clear();
  }

  return 0;
}