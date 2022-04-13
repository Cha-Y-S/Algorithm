#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> v;
int A, B, idx, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B;

  v = vector<int>(1000);
  idx = 0;

  for (int i = 1; i <= 1000; i++) {
    for (int j = 0; j < i && idx < 1000; j++) {
      v[idx++] = i;
    }
  }

  for (int i = A - 1; i < B; i++) {
    res += v[i];
  }

  cout << res << endl;

  return 0;
}