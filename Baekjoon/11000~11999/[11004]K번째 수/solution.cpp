#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> A;
int N, K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  A = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  cout << A[K - 1] << endl;

  return 0;
}