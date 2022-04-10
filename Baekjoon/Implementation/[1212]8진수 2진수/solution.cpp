#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string octal;
string res;

void get_binary(int n);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> octal;

  for (int i = 0; i < octal.size(); i++) {
    get_binary(octal[i] - '0');
    if (i == 0) {
      if (res == "000") {
        res = "0";
        break;
      }
      int idx = 0;

      while (res[idx] != '1') {
        idx++;
      }

      res = res.substr(idx);
    }
  }

  cout << res << endl;

  return 0;
}

void get_binary(int n) {
  string result = "";
  int cnt = 0;

  while (n != 0) {
    result = to_string(n % 2) + result;

    n /= 2;
    cnt++;
  }

  for (int i = cnt; i < 3; i++) {
    result = "0" + result;
  }

  res += result;
}