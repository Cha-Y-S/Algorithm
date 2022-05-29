#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> triangle;
int T, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  triangle = vector<int>(302, 1);

  for (int i = 2; i <= 301; i++) {
    triangle[i] = triangle[i - 1] + i;
  }

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N;

    int res = 0;

    for (int j = 1; j <= N; j++) {
      res += j * triangle[j + 1];
    }

    cout << res << endl;
  }

  return 0;
}