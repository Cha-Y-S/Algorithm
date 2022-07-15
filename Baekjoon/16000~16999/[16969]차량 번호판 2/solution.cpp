#include <iostream>
#include <string>

using namespace std;

#define endl "\n"
#define MOD 1'000'000'009

string n_format;
long long res;
bool flag;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n_format;
  res = 1;

  for (int i = 0; i < n_format.length(); i++) {
    if (i == 0) {
      if (n_format[i] == 'c') {
        flag = false;
        res = (res * 26) % MOD;
      } else {
        flag = true;
        res = (res * 10) % MOD;
      }
      continue;
    }

    if (n_format[i] == 'c') {
      res = (res * (flag ? 26 : 25)) % MOD;
      flag = false;
    } else {
      res = (res * (flag ? 9 : 10)) % MOD;
      flag = true;
    }
  }

  cout << res << endl;

  return 0;
}