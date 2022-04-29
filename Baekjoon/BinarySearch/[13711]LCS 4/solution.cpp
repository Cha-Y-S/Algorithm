#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> A, seq, lis;
int N, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  A = vector<int>(N);

  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int i = 0; i < N; i++) {
    cin >> num;

    int target = find(A.begin(), A.end(), num) - A.begin();

    int idx = lower_bound(lis.begin(), lis.end(), target) - lis.begin();

    if (idx == lis.size())
      lis.push_back(target);
    else
      lis[idx] = target;
  }

  cout << lis.size() << endl;

  return 0;
}