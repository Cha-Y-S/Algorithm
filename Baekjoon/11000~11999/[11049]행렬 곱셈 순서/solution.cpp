#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define INF 2'147'483'647

void fastIO();
void initData();
int getMinCalcCnt();

vector<vector<int>> matrix, dp;
int N;

int main() {
  fastIO();

  initData();

  cout << getMinCalcCnt() << endl;

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> N;

  matrix = vector<vector<int>>(503, vector<int>(2, 0));
  dp = vector<vector<int>>(503, vector<int>(503, 0));

  for (int i = 1; i <= N; i++) {
    cin >> matrix[i][0] >> matrix[i][1];
  }
}

int getMinCalcCnt() {
  for (int i = 1; i < N; i++) {
    for (int j = 1; i + j <= N; j++) {
      dp[j][i + j] = INF;
      for (int k = j; k <= i + j; k++) {
        dp[j][i + j] = min(dp[j][i + j],
                           dp[j][k] + dp[k + 1][i + j] +
                               matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
      }
    }
  }

  return dp[1][N];
}
