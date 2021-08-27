#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, n;

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    vector<int> input(n);
    long long sum = 0;

    for (int i = 0; i < n; i++)
      cin >> input[i];

    for (int i = 0; i < input.size(); i++) {
      for (int j = i + 1; j < input.size(); j++) {
        int a = input[i];
        int b = input[j];

        if (a < b) {
          int temp = a;
          a = b;
          b = temp;
        }

        while (a % b != 0) {
          int temp = a;
          a = b;
          b = temp % b;
        }
        sum += b;
      }
    }
    cout << sum << endl;
  }

  return 0;
}