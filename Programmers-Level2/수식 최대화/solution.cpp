#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(string expression) {
  long long answer = 0;
  vector<long long> num;
  vector<char> op;
  vector<char> op_loc;
  string number = "";

  // Extract operator, operator's sequence and operand from expression
  for (int i = 0; i < expression.size(); i++) {
    if (isdigit(expression[i]))
      number += expression[i];
    else {
      if (find(op.begin(), op.end(), expression[i]) == op.end())
        op.push_back(expression[i]);
      op_loc.push_back(expression[i]);
      num.push_back(stoll(number));
      number = "";
    }
  }

  num.push_back(stoll(number));
  sort(op.begin(), op.end());

  // Making combination that is possible by operator's priority
  do {
    vector<long long> tmp_num = num;
    vector<char> tmp_loc = op_loc;

    for (int i = 0; i < op.size(); i++) {
      for (int j = 0; j < tmp_loc.size(); j++) {
        if (op[i] == tmp_loc[j]) {
          switch (op[i]) {
            case '*':
              tmp_num[j + 1] = tmp_num[j] * tmp_num[j + 1];
              break;
            case '+':
              tmp_num[j + 1] = tmp_num[j] + tmp_num[j + 1];
              break;
            case '-':
              tmp_num[j + 1] = tmp_num[j] - tmp_num[j + 1];
              break;
          }
          tmp_loc.erase(tmp_loc.begin() + j);
          tmp_num.erase(tmp_num.begin() + j);
          j--;
        }
      }
    }
    // Get maximum absolute number of result made from operator's priority
    answer = max(answer, abs(tmp_num[0]));
  } while (next_permutation(op.begin(), op.end()));

  return answer;
}