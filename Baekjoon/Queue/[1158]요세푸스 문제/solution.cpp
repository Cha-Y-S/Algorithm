#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"

queue<int> q;
int N, K, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  cnt = 0;

  for (int i = 1; i <= N; i++)
    q.push(i);

  cout << "<";
  while (!q.empty()) {
    int cur = q.front();

    q.pop();
    cnt++;

    if (cnt == K) {
      cout << cur;
      cnt = 0;
      if (!q.empty())
        cout << ", ";
      continue;
    }

    q.push(cur);
  }
  cout << ">";

  return 0;
}