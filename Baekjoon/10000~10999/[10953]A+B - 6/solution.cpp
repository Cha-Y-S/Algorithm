#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;

  cin >> t;

  for (; t > 0; t--) {
    string input;

    cin >> input;

    cout << input[0] - '0' + input[2] - '0' << endl;
  }

  return 0;
}