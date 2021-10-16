#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

int N, i;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  i = 666;

  while (N != 0) {
    string temp = to_string(i);
    bool flag = false;

    for (int j = 0; j < temp.size() - 2; j++) {
      if (temp[j] == '6' && temp[j + 1] == '6' && temp[j + 2] == '6') flag = true;
    }

    if (flag) N--;

    i++;
  }

  cout << i - 1 << endl;

  return 0;
}