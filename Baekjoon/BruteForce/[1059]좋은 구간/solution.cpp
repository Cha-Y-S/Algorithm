#include <iostream>
#include <set>

using namespace std;

#define endl "\n"

set<int> s;
int L, N, lower, upper, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> L;

  res = 0;

  s.insert(0);
  for (int i = 0; i < L; i++) {
    cin >> N;
    s.insert(N);
  }

  cin >> N;

  set<int>::iterator it = s.begin();

  while (it != --s.end()) {
    int cur = *it;
    int next = *(++it);

    lower = cur + 1;
    upper = next;

    if (lower > N) break;

    for (int i = lower; i < upper - 1; i++) {
      for (int j = i + 1; j < upper; j++) {
        if (i <= N && N <= j) res++;
      }
    }
  }

  cout << res << endl;

  return 0;
}