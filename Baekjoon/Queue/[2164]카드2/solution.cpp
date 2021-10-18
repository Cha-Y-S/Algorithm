#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"

queue<int> q;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++)
    q.push(i + 1);

  while (q.size() != 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }

  cout << q.front() << endl;

  return 0;
}