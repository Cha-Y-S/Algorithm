#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string N;

string mul17(string n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  cout << mul17(N) << endl;

  return 0;
}

string mul17(string n) {
  string left = n + "0000";
  string right = n;
  string result = "";

  while (left.size() != right.size()) {
    right = "0" + right;
  }

  bool carry = false;
  for (int i = left.size() - 1; i >= 0; i--) {
    if (left[i] == '0' && right[i] == '0') {
      if (carry) {
        result = "1" + result;
      } else {
        result = "0" + result;
      }
      carry = false;
    } else if (left[i] == '1' && right[i] == '1') {
      if (carry) {
        result = "1" + result;
      } else {
        result = "0" + result;
      }
      carry = true;
    } else {
      if (carry) {
        result = "0" + result;
        carry = true;
      } else {
        result = "1" + result;
        carry = false;
      }
    }
  }

  result = carry ? "1" + result : result;

  return result;
}