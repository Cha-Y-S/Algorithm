#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string K;
int N, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  res = 0;

  for (int i = 0; i < N; i++) {
    if (K[i] == '1') res++;
  }

  cout << res << endl;

  return 0;
}