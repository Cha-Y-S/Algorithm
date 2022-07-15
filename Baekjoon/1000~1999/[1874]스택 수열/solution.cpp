#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define endl "\n"

stack<int> stk;
vector<int> seq;
vector<char> method;
int N, pointer;
bool flag;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  cin >> N;
  seq = vector<int>(N);
  pointer = 0;

  for (int i = 0; i < N; i++)
    cin >> seq[i];

  for (int i = 0; i < N; i++) {
    stk.push(i + 1);
    method.push_back('+');
    while (!stk.empty() && stk.top() == seq[pointer]) {
      stk.pop();
      method.push_back('-');
      pointer++;
    }
  }

  if (stk.empty()) {
    for (int i = 0; i < method.size(); i++)
      cout << method[i] << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}