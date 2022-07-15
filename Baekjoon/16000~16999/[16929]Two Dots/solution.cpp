#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
typedef pair<int, int> pii;

bool cycle = false;
vector<vector<bool>> visited;
vector<vector<int>> matrix;
vector<pii> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(pii s, pii cur, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  cin >> n >> m;

  visited = vector<vector<bool>>(n, vector<bool>(m, false));
  matrix = vector<vector<int>>(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char input;
      cin >> input;
      matrix[i][j] = input - 'A' + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        pii start = {i, j};
        dfs(start, {i, j}, 1);
        visited[i][j] = true;
      }
      if (cycle) break;
    }
    if (cycle) break;
  }
  if (cycle)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

void dfs(pii s, pii cur, int cnt) {
  int cx = cur.first;
  int cy = cur.second;

  if (visited[cx][cy]) return;

  visited[cx][cy] = true;

  for (int i = 0; i < dir.size(); i++) {
    int nx = cx + dir[i].first;
    int ny = cy + dir[i].second;

    if ((0 <= nx && nx < matrix.size()) && (0 <= ny && ny < matrix[nx].size())) {
      if (matrix[nx][ny] == matrix[cx][cy] && !visited[nx][ny])
        dfs(s, {nx, ny}, cnt + 1);
      else if (s.first == nx && s.second == ny && cnt >= 4) {
        cycle = true;
        return;
      }
    }
  }
  visited[cx][cy] = false;
}