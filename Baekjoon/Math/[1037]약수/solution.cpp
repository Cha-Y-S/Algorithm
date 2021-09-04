#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  vector<int> divs(n, 0);

  for (int i = 0; i < n; i++)
    cin >> divs[i];

  sort(divs.begin(), divs.end());

  cout << divs[0] * divs[n - 1] << endl;

  return 0;
}