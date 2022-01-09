#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

#define endl "\n"

map<char, int> prio;
stack<char> stk;
string expr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> expr;

  prio = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

  for (char c : expr) {
    if (isalpha(c))
      cout << c;
    else {
      if (c == '(')
        stk.push(c);
      else if (c == ')') {
        while (!stk.empty() && stk.top() != '(') {
          cout << stk.top();
          stk.pop();
        }
        stk.pop();
      } else {
        while (!stk.empty() && stk.top() != '(' && prio[stk.top()] >= prio[c]) {
          cout << stk.top();
          stk.pop();
        }
        stk.push(c);
      }
    }
  }
  while (!stk.empty()) {
    cout << stk.top();
    stk.pop();
  }
  cout << endl;

  return 0;
}
