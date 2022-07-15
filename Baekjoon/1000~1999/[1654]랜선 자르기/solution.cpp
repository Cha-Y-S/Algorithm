#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<long long> lan;
int K, N;
long long l, r, mid, total, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> K >> N;

  lan = vector<long long>(K);
  l = 1;
  r = 0;
  res = 0;

  for (int i = 0; i < K; i++) {
    cin >> lan[i];

    r = lan[i] > r ? lan[i] : r;
  }

  while (l <= r) {
    mid = (l + r) / 2;
    total = 0;

    for (int i = 0; i < K; i++)
      total += lan[i] / mid;

    if (total >= N) {
      l = mid + 1;
      res = res < mid ? mid : res;
    } else
      r = mid - 1;
  }

  cout << res << endl;

  return 0;
}