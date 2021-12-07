#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> board;
vector<vector<vector<bool>>> visited;
vector<pii> dirs;
string row;
pii start;
int N, M, res;

int bfs(pii start);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  board = vector<vector<char>>(N, vector<char>(M));
  visited = vector<vector<vector<bool>>>(N, vector<vector<bool>>(M, vector<bool>(1 << 6, false)));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    cin >> row;

    for (int j = 0; j < M; j++) {
      board[i][j] = row[j];

      if (board[i][j] == '0') {
        start = {i, j};
        board[i][j] = '.';
      }
    }
  }

  res = bfs(start);

  cout << res << endl;

  return 0;
}

bool has_key(int key, char door) {
  return (key & (1 << int(door - 'A'))) != 0 ? true : false;
}

int bfs(pii start) {
  queue<pair<pii, pii>> q;

  q.push({start, {0, 0}});
  visited[start.first][start.second][0] = true;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int cnt = q.front().second.first;
    int key = q.front().second.second;

    q.pop();

    if (board[cx][cy] == '1') return cnt;

    for (int i = 0; i < 4; i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
        if (!visited[nx][ny][key]) {
          if (board[nx][ny] == '.' || board[nx][ny] == '1') {
            visited[nx][ny][key] = true;
            q.push({{nx, ny}, {cnt + 1, key}});
          } else if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
            int temp = key | (1 << (int(board[nx][ny] - 'a')));
            visited[nx][ny][temp] = true;
            q.push({{nx, ny}, {cnt + 1, temp}});
          } else if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
            if (has_key(key, board[nx][ny])) {
              visited[nx][ny][key] = true;
              q.push({{nx, ny}, {cnt + 1, key}});
            }
          }
        }
      }
    }
  }

  return -1;
}