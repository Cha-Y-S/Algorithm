#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> board;
vector<vector<bool>> visited;
vector<pii> dirs;
string input_key;
int initial_key;
int T, H, W, D;

bool has_key(int key_state, char door);
int bfs(pii start, int s_key);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (; T > 0; T--) {
    cin >> H >> W;

    board = vector<vector<char>>(H + 2, vector<char>(W + 2, '.'));
    visited = vector<vector<bool>>(H + 2, vector<bool>(W + 2, false));

    initial_key = 0;
    D = 0;

    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cin >> board[i][j];

        if (board[i][j] == '$') D++;
      }
    }

    cin >> input_key;

    for (int i = 0; i < input_key.size(); i++) {
      if (input_key[i] == '0') continue;
      initial_key |= (1 << (input_key[i] - 'a'));
    }

    cout << bfs({0, 0}, initial_key) << endl;

    board.clear();
    visited.clear();
  }

  return 0;
}

bool has_key(int key_state, char door) {
  return (key_state & (1 << (door - 'A'))) != 0 ? true : false;
}

int bfs(pii start, int s_key) {
  queue<pair<pii, int>> q;
  int doc_cnt = 0;

  q.push({start, s_key});
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int key_state = q.front().second;

    q.pop();

    if (doc_cnt == D) return doc_cnt;

    for (int i = 0; i < dirs.size(); i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if ((0 <= nx && nx < H + 2) && (0 <= ny && ny < W + 2)) {
        if (!visited[nx][ny]) {
          if (board[nx][ny] == '.') {
            q.push({{nx, ny}, key_state});
            visited[nx][ny] = true;
          } else if (board[nx][ny] == '$') {
            doc_cnt++;
            board[nx][ny] = '.';
            q.push({{nx, ny}, key_state});
            visited[nx][ny] = true;
          } else if ('a' <= board[nx][ny] && board[nx][ny] <= 'z') {
            int update_key = key_state | (1 << (board[nx][ny] - 'a'));
            board[nx][ny] = '.';

            visited = vector<vector<bool>>(H + 2, vector<bool>(W + 2, false));
            q = queue<pair<pii, int>>();

            q.push({{nx, ny}, update_key});
            visited[nx][ny] = true;
            break;
          } else if ('A' <= board[nx][ny] && board[nx][ny] <= 'Z') {
            if (has_key(key_state, board[nx][ny])) {
              board[nx][ny] = '.';
              q.push({{nx, ny}, key_state});
              visited[nx][ny] = true;
            }
          }
        }
      }
    }
  }

  return doc_cnt;
}