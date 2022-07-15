#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> H;
int N, L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> L;

  H = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  sort(H.begin(), H.end());

  for (int i = 0; i < N; i++) {
    if (H[i] > L) break;

    L += 1;
  }

  cout << L << endl;

  return 0;
}