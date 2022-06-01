#include <iostream>

using namespace std;

#define endl "\n"

int T, J;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  while (T--) {
    cin >> J;

    for (int i = 0; i < J; i++) {
      for (int j = 0; j < J; j++) {
        if (i == 0 || i == J - 1 || j == 0 || j == J - 1) {
          cout << "#";
        } else {
          cout << "J";
        }
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}