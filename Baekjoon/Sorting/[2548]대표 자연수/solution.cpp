#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> naturals;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  naturals = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> naturals[i];
  }

  sort(naturals.begin(), naturals.end());

  int q = N / 2;
  int r = N % 2;

  cout << naturals[q + r - 1] << endl;

  return 0;
}