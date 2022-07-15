#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string input;
int res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    getline(cin, input);

    if (input == "#") break;

    res = 0;

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == 'a' || input[i] == 'e' || input[i] == 'u' || input[i] == 'i' || input[i] == 'o') {
        res++;
      }

      if (input[i] == 'A' || input[i] == 'E' || input[i] == 'U' || input[i] == 'I' || input[i] == 'O') {
        res++;
      }
    }

    cout << res << endl;
  }

  return 0;
}