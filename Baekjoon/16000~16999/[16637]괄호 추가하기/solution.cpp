#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string expression;
int N, res;

void fast_io();
void add_parentheses(int idx, int cur);
int calculate_expression(int left, int right, char oper);

int main() {
  fast_io();

  cin >> N >> expression;

  res = INT_MIN;

  add_parentheses(0, 0);

  cout << res << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void add_parentheses(int idx, int cur) {
  if (idx > N - 1) {
    res = max(res, cur);
    return;
  }

  char oper = (idx == 0) ? '+' : expression[idx - 1];

  // Add parentheses first, if it is possible
  if (idx + 2 < N) {
    // Calculate current value and value of parentheses
    int parentheses = calculate_expression(
        expression[idx] - '0', expression[idx + 2] - '0', expression[idx + 1]);
    add_parentheses(idx + 4, calculate_expression(cur, parentheses, oper));
  }

  // Step into next operation
  add_parentheses(idx + 2,
                  calculate_expression(cur, expression[idx] - '0', oper));
}

int calculate_expression(int left, int right, char oper) {
  int result = left;
  switch (oper) {
    case '+':
      result += right;
      break;
    case '-':
      result -= right;
      break;
    case '*':
      result *= right;
      break;
  }
  return result;
}