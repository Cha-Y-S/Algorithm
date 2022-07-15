#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

string a, b, res;
int N;

string sum(string x, string y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  a = "0";
  b = "1";

  if (N == 0)
    res = a;
  else if (N == 1)
    res = b;
  else {
    for (int i = 2; i <= N; i++) {
      res = sum(a, b);
      a = b;
      b = res;
    }
  }

  cout << res << endl;

  return 0;
}

string sum(string x, string y) {
  string result = "";
  int carry = 0;

  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());

  while (x.size() < y.size())
    x += '0';

  while (x.size() > y.size())
    y += '0';

  for (int i = 0; i < x.size(); i++) {
    result += to_string(((x[i] - '0') + (y[i] - '0') + carry) % 10);
    carry = ((x[i] - '0') + (y[i] - '0') + carry) / 10;
  }

  if (carry > 0) result += to_string(carry);

  reverse(result.begin(), result.end());

  return result;
}