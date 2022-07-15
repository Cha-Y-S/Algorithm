#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> straws;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  straws = vector<int>(N);
  res = -1;

  for (int i = 0; i < N; i++) {
    cin >> straws[i];
  }

  sort(straws.begin(), straws.end(), greater<>());

  for (int i = 0; i < N - 2; i++) {
    if (straws[i] < straws[i + 1] + straws[i + 2]) {
      res = straws[i] + straws[i + 1] + straws[i + 2];
      break;
    }
  }

  cout << res << endl;

  return 0;
}