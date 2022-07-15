#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<bool> eratos;
int A, B, res;

int factorization(int target);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B;

  eratos = vector<bool>(B + 1, true);
  res = 0;

  eratos[0] = false;
  eratos[1] = false;

  for (int i = 2; i < B + 1; i++) {
    if (!eratos[i]) continue;
    for (int j = i + i; j < B + 1; j += i)
      eratos[j] = false;
  }

  for (int i = A; i <= B; i++) {
    if (eratos[factorization(i)]) res++;
  }

  cout << res << endl;

  return 0;
}

int factorization(int target) {
  int result = 0;

  while (target != 1) {
    for (int i = 2; i <= target; i++) {
      if (eratos[i] && target % i == 0) {
        result++;
        target /= i;

        break;
      }
    }
  }

  return result;
}