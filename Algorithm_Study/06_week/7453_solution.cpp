#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> ABCD;
vector<int> AB;
vector<int> CD;
long long res;
int N, ab_idx, cd_idx;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  ABCD = vector<vector<int>>(4, vector<int>(N));
  AB = vector<int>(N * N);
  CD = vector<int>(N * N);
  ab_idx = res = 0;
  cd_idx = N * N - 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++)
      cin >> ABCD[j][i];
  }

  for (int i = 0, idx = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      AB[idx] = ABCD[0][i] + ABCD[1][j];
      CD[idx] = ABCD[2][i] + ABCD[3][j];
      idx++;
    }
  }

  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  while (ab_idx < N * N && cd_idx >= 0) {
    if (AB[ab_idx] + CD[cd_idx] == 0) {
      int origin = ab_idx;
      long long ab = 0, cd = 0;

      while (AB[ab_idx] + CD[cd_idx] == 0) {
        if (ab_idx >= N * N) break;
        ab++;
        ab_idx++;
      }

      while (AB[origin] + CD[cd_idx] == 0) {
        if (cd_idx < 0) break;
        cd++;
        cd_idx--;
      }
      res = res + (ab * cd);
    } else if (AB[ab_idx] + CD[cd_idx] > 0)
      cd_idx--;
    else
      ab_idx++;
  }

  cout << res << endl;

  return 0;
}