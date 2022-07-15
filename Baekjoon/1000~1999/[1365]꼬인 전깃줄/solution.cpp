#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> lis;
int N, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num;

    int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();

    if (idx == lis.size())
      lis.push_back(num);
    else
      lis[idx] = num;
  }

  cout << N - lis.size() << endl;

  return 0;
}