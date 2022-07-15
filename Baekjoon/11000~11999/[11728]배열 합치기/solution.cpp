#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> A;
vector<int> B;
vector<int> res;
int N, M, a_idx, b_idx;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  A = vector<int>(N);
  B = vector<int>(M);
  a_idx = b_idx = 0;

  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int i = 0; i < M; i++)
    cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  while (true) {
    if (a_idx >= N && b_idx >= M)
      break;
    else if (a_idx >= N) {
      for (; b_idx < M; b_idx++)
        res.push_back(B[b_idx]);
    } else if (b_idx >= M) {
      for (; a_idx < N; a_idx++)
        res.push_back(A[a_idx]);
    } else {
      if (A[a_idx] < B[b_idx])
        res.push_back(A[a_idx++]);
      else
        res.push_back(B[b_idx++]);
    }
  }

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}