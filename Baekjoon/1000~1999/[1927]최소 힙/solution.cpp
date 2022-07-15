#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"

priority_queue<int, vector<int>, greater<int>> pq;
int N, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num;

    if (num == 0) {
      if (pq.empty())
        cout << 0 << endl;
      else {
        cout << pq.top() << endl;
        pq.pop();
      }
    } else
      pq.push(num);
  }

  return 0;
}