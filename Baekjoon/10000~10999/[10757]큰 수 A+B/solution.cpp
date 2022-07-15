#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

void performAdd(string &s, int &up, int sum);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string a, b;
  string result = "";
  int ai, bi, up;

  cin >> a >> b;

  ai = a.size() - 1;
  bi = b.size() - 1;
  up = 0;

  while (!(ai < 0 && bi < 0)) {
    if (ai < 0) {
      for (int i = bi; i >= 0; i--) {
        int sum = (b[bi--] - '0') + up;

        performAdd(result, up, sum);
      }
      break;
    }

    if (bi < 0) {
      for (int i = ai; i >= 0; i--) {
        int sum = (a[ai--] - '0') + up;

        performAdd(result, up, sum);
      }
      break;
    }

    int sum = (a[ai--] - '0') + (b[bi--] - '0') + up;

    performAdd(result, up, sum);
  }

  result = up == 1 ? (char)(up + '0') + result : result;

  cout << result << endl;

  return 0;
}

void performAdd(string &s, int &up, int sum) {
  if (sum < 10) {
    up = 0;
  } else {
    up = 1;
    sum %= 10;
  }

  s = (char)(sum + '0') + s;
}