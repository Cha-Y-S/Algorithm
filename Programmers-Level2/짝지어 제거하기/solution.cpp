#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string s) {
  int answer = -1;
  stack<int> st;

  for (int i = 0; i < s.size(); i++) {
    if (st.empty()) {
      st.push(s[i]);
      continue;
    }

    if (st.top() == s[i])
      st.pop();
    else
      st.push(s[i]);
  }

  answer = st.empty() ? 1 : 0;

  return answer;
}