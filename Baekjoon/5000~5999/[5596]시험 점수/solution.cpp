#include <iostream>

using namespace std;

#define endl "\n"

int sum1, sum2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sum1 = sum2 = 0;

  for (int i = 0; i < 4; i++) {
    int num;

    cin >> num;

    sum1 += num;
  }

  for (int i = 0; i < 4; i++) {
    int num;

    cin >> num;

    sum2 += num;
  }

  cout << (sum1 < sum2 ? sum2 : sum1) << endl;

  return 0;
}