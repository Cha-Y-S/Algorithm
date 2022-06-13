#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define endl "\n"

queue<int> q;
string oper;
int N, target;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> oper;

    if (oper == "push") {
      cin >> target;

      q.push(target);
    } else if (oper == "pop") {
      if (q.empty()) {
        cout << "-1" << endl;
        continue;
      }
      cout << q.front() << endl;
      q.pop();
    } else if (oper == "size") {
      cout << q.size() << endl;
    } else if (oper == "empty") {
      cout << (q.empty() ? 1 : 0) << endl;
    } else if (oper == "front") {
      if (q.empty()) {
        cout << "-1" << endl;
        continue;
      }
      cout << q.front() << endl;
    } else {
      if (q.empty()) {
        cout << "-1" << endl;
        continue;
      }
      cout << q.back() << endl;
    }
  }

  return 0;
}