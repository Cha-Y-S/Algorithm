#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

struct qual {
  int power;
  int motor;
  int cable;
  bool result;
};

vector<qual> test;
vector<int> res;
int A, B, C, N, R;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B >> C >> N;

  res = vector<int>(A + B + C, 2);
  test = vector<qual>(N);

  for (int i = 0; i < N; i++) {
    cin >> test[i].power >> test[i].motor >> test[i].cable >> R;
    test[i].power -= 1;
    test[i].motor -= 1;
    test[i].cable -= 1;
    test[i].result = R == 1 ? true : false;
  }

  for (int i = 0; i < N; i++) {
    if (test[i].result) {
      res[test[i].power] = 1;
      res[test[i].motor] = 1;
      res[test[i].cable] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (!test[i].result) {
      int cnt = 0;

      if (res[test[i].power] == 1) cnt++;
      if (res[test[i].motor] == 1) cnt++;
      if (res[test[i].cable] == 1) cnt++;

      if (cnt == 2) {
        if (res[test[i].power] == 2) res[test[i].power] = 0;
        if (res[test[i].motor] == 2) res[test[i].motor] = 0;
        if (res[test[i].cable] == 2) res[test[i].cable] = 0;
      }
    }
  }

  for (int i = 0; i < A + B + C; i++) {
    cout << res[i] << endl;
  }

  return 0;
}