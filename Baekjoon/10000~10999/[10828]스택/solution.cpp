#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl "\n"

stack<int> stk;
string CMD;
int N, X;

void fast_io();

int main() {
  fast_io();

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> CMD;

    if (CMD == "push") {
      cin >> X;
      stk.push(X);
    } else if (CMD == "pop") {
      if (stk.empty()) {
        cout << -1 << endl;
      } else {
        cout << stk.top() << endl;
        stk.pop();
      }
    } else if (CMD == "size") {
      cout << stk.size() << endl;
    } else if (CMD == "empty") {
      cout << (stk.empty() ? 1 : 0) << endl;
    } else {
      if (stk.empty()) {
        cout << -1 << endl;
      } else {
        cout << stk.top() << endl;
      }
    }
  }

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}