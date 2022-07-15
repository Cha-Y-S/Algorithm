#include <iostream>

using namespace std;

#define endl "\n"

typedef long long ll;

ll N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  cout << N * (N - 1) / 2 << endl;

  return 0;
}