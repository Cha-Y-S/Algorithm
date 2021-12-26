#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix, numbering;
vector<vector<bool>> visited;
vector<int> v;
vector<pii> dir;
int N, M;

int bfs(int x, int y, int c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  matrix = vector<vector<int>>(N, vector<int>(M, 0));
  numbering = vector<vector<int>>(N, vector<int>(M, 0));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < M; j++) {
      matrix[i][j] = input[j] - '0';
    }
  }

  int cluster = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (matrix[i][j] == 0 && !visited[i][j]) {
        v.push_back(bfs(i, j, ++cluster));
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (matrix[i][j] == 1) {
        set<int> s;

        for (int k = 0; k < dir.size(); k++) {
          int nx = i + dir[k].first;
          int ny = j + dir[k].second;

          if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

          if (matrix[nx][ny] == 0 && s.find(numbering[nx][ny]) == s.end()) {
            s.insert(numbering[nx][ny]);
          }
        }
        for (int e : s) {
          matrix[i][j] += v[e - 1];
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cout << matrix[i][j] % 10;
    cout << endl;
  }

  return 0;
}

int bfs(int x, int y, int c) {
  queue<pii> q;
  int cnt = 1;

  q.push({x, y});
  numbering[x][y] = c;
  visited[x][y] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      if (matrix[nx][ny] == 0 && !visited[nx][ny]) {
        visited[nx][ny] = true;
        numbering[nx][ny] = c;
        q.push({nx, ny});
        cnt++;
      }
    }
  }

  return cnt;
}