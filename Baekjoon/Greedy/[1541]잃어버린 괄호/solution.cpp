#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> operands;
string expression;
stringstream st;
int op, res;
char opt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> expression;

  st.str(expression);

  st >> op;

  operands.push_back(op);

  while (st >> opt >> op) {
    if (opt == '+')
      operands[operands.size() - 1] = operands[operands.size() - 1] + op;
    else
      operands.push_back(op);
  }

  res = operands[0];

  for (int i = 1; i < operands.size(); i++)
    res -= operands[i];

  cout << res << endl;

  return 0;
}