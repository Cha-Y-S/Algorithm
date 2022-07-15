#include <iostream>

using namespace std;

#define endl "\n"

int N, call, Y, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  Y = M = 0;

  for (int i = 0; i < N; i++) {
    cin >> call;

    Y += ((call / 30) + 1) * 10;
    M += ((call / 60) + 1) * 15;
  }

  if (Y < M) {
    cout << "Y " << Y << endl;
  } else if (Y > M) {
    cout << "M " << M << endl;
  } else {
    cout << "Y M " << Y << endl;
  }

  return 0;
}