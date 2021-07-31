#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
  int answer = 0;
  string copy = s;

  for (int i = 0; i < s.size(); i++) {
    stack<char> st;

    // Check that either the bracket string is right or not
    for (int j = 0; j < copy.size(); j++) {
      if (copy[j] == '[' || copy[j] == '{' || copy[j] == '(')
        st.push(copy[j]);
      else {
        if (st.empty()) {
          // If the bracket string is not right, make stack that will be not empty
          st.push(copy[j]);
          break;
        } else {
          if ((copy[j] == ']' && st.top() == '[') || (copy[j] == '}' && st.top() == '{') || (copy[j] == ')' && st.top() == '('))
            st.pop();
          else
            break;
        }
      }
    }

    answer = st.empty() ? answer + 1 : answer;

    copy.push_back(copy[0]);
    copy.erase(copy.begin(), copy.begin() + 1);
  }

  return answer;
}