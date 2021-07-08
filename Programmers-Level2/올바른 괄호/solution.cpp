#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
  bool answer = true;
  stack<char> stk;

  for (int i = 0; i < s.size(); i++) {
    if (stk.empty() || stk.top() == s[i])
      stk.push(s[i]);
    else if (stk.top() != s[i] && stk.top() == '(')
      stk.pop();
    else if (stk.top() != s[i] && stk.top() == ')')
      stk.push(s[i]);
  }

  answer = stk.empty() ? true : false;

  return answer;
}