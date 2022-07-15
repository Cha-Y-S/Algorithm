#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl "\n"

stack<char> stk;
string S, res;
int idx;

void add_character_from_stack_to_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  getline(cin, S);
  res = "";
  idx = 0;

  while (idx < S.size()) {
    if (S[idx] == '<') {
      add_character_from_stack_to_res();
      while (S[idx] != '>') {
        res += S[idx++];
      }
      res += ">";
    } else if (S[idx] == ' ') {
      add_character_from_stack_to_res();
      res += " ";
    } else {
      stk.push(S[idx]);
    }
    idx++;
  }

  add_character_from_stack_to_res();

  cout << res << endl;

  return 0;
}

void add_character_from_stack_to_res() {
  while (!stk.empty()) {
    res += stk.top();

    stk.pop();
  }
}