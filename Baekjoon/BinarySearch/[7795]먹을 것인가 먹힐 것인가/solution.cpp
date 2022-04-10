#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> A;
vector<int> B;
int T, N, M, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  while (T--) {
    cin >> N >> M;

    A = vector<int>(N);
    B = vector<int>(M);
    res = 0;

    for (int i = 0; i < N; i++)
      cin >> A[i];

    for (int i = 0; i < M; i++)
      cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
      int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();

      res += idx;
    }

    cout << res << endl;
  }

  return 0;
}