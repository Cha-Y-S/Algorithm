#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, double> pid;

vector<vector<pid>> graph;
vector<vector<double>> dp;
int t, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed;
  cout.precision(2);

  cin >> t >> M;
  graph = vector<vector<pid>>(4);
  dp = vector<vector<double>>(4, vector<double>(t + 1, 0));
  dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 0.25;

  for (int i = 0; i < M; i++) {
    char s, e;
    double prob;

    cin >> s >> e >> prob;

    graph[s - 'A'].push_back({e - 'A', prob});
  }

  for (int k = 0; k < t; k++) {
    for (int i = 0; i < graph.size(); i++) {
      for (pid p : graph[i]) {
        dp[p.first][k + 1] += dp[i][k] * p.second;
      }
    }
  }

  for (int i = 0; i < 4; i++)
    cout << dp[i][t] * 100 << endl;

  return 0;
}