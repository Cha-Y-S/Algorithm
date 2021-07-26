#include <stack>
#include <string>
#include <vector>

using namespace std;

bool isProperString(string s);

string solution(string p) {
  string answer = "";
  string u, v;
  int balance = 0;
  int i = 0;

  // Step 1: Return empty string
  if (p == "")
    return p;

  // Step 2: Divide string to u, v
  do {
    u.push_back(p[i]);
    balance = p[i++] == '(' ? balance + 1 : balance - 1;
  } while (balance != 0);

  for (; i < p.size(); i++)
    v.push_back(p[i]);

  // Check that is string u proper
  if (isProperString(u)) {
    // Step 3: When string u is proper
    answer += u + solution(v);
  } else {
    // Step 4: When string u is not proper, call recursive function with v
    answer += '(' + solution(v) + ')';

    string temp;
    for (int i = 1; i < u.size() - 1; i++) {
      if (u[i] == '(')
        temp.push_back(')');
      else
        temp.push_back('(');
    }

    answer += temp;
  }

  return answer;
}

bool isProperString(string s) {
  stack<char> st;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      st.push(s[i]);
    else {
      if (st.empty())
        return false;
      else {
        st.pop();
      }
    }
  }

  if (st.empty())
    return true;

  return false;
}