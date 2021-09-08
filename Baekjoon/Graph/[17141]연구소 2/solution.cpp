#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

void printMatrix(vector<vector<int>> matrix);
int bfs(vector<vector<int>> m, vector<pii> v, int z);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(n, 0));
  vector<pii> viruses;

  int v_cnt = 0;
  int z_cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];

      if (matrix[i][j] == 1)
        matrix[i][j] = -1;
      else if (matrix[i][j] == 2) {
        matrix[i][j] = 0;
        viruses.push_back({i, j});
      } else {
        z_cnt++;
      }
    }
  }

  z_cnt += viruses.size() - m;
  vector<bool> pick(viruses.size() - m, false);
  pick.insert(pick.end(), m, true);

  int time = -1;
  do {
    vector<pii> active;

    for (int i = 0; i < pick.size(); i++) {
      if (pick[i]) active.push_back(viruses[i]);
    }

    int cur = bfs(matrix, active, z_cnt);

    if (cur != -1 && time != -1)
      time = time < cur ? time : cur;
    else if (cur != -1 && time == -1)
      time = cur;

  } while (next_permutation(pick.begin(), pick.end()));

  cout << time << endl;

  return 0;
}

int bfs(vector<vector<int>> m, vector<pii> v, int z) {
  int result = 0;
  int spread = 0;
  vector<pii> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  queue<pii> q;

  for (int i = 0; i < v.size(); i++) {
    q.push(v[i]);
    m[v[i].first][v[i].second] = 1;
  }

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    result = result < m[cx][cy] - 1 ? m[cx][cy] - 1 : result;

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < m.size()) && (0 <= ny && ny < m[nx].size()) && m[nx][ny] == 0) {
        m[nx][ny] = m[cx][cy] + 1;
        spread++;
        q.push({nx, ny});
      }
    }
  }

  if (spread != z) result = -1;

  return result;
}