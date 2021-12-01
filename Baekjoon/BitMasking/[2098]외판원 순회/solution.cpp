#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321;
#define endl "\n"

vector<vector<int>> W;
vector<vector<int>> dp;
int N;

int traveling_salesman_problem(int cur, int visited);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  W = vector<vector<int>>(N, vector<int>(N));
  dp = vector<vector<int>>(N, vector<int>(1 << N, -1));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      cin >> W[i][j];
  }

  cout << traveling_salesman_problem(0, 1) << endl;

  return 0;
}

int traveling_salesman_problem(int cur, int visited) {
  int res = dp[cur][visited];

  if (res != -1) return res;

  if (visited == (1 << N) - 1) {
    if (W[cur][0] != 0)
      return W[cur][0];
    return INF;
  }

  res = INF;
  for (int i = 0; i < N; i++) {
    if (visited & (1 << i) || W[cur][i] == 0)
      continue;
    res = min(res, traveling_salesman_problem(i, visited | (1 << i)) + W[cur][i]);
  }

  dp[cur][visited] = res;

  return res;
}