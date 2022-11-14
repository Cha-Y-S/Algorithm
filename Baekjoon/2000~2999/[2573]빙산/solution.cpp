#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

void fastIO();
void initData();
int getMinYear();
void labelBoard(int x, int y);
void meltGlacier();

vector<vector<int>> board;
vector<vector<bool>> visited;
vector<pii> dirs;
int N, M;

int main() {
  fastIO();

  initData();

  cout << getMinYear() << endl;

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> N >> M;

  board = vector<vector<int>>(N, vector<int>(M, 0));

  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
}

int getMinYear() {
  int result = 0;
  int labelNum;

  while (true) {
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    labelNum = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (!visited[i][j] && board[i][j] != 0) {
          labelBoard(i, j);
          labelNum++;
        }
      }
    }

    if (labelNum != 1) break;

    meltGlacier();
    result++;
  }

  result = labelNum == 0 ? 0 : result;

  return result;
}

void labelBoard(int x, int y) {
  queue<pii> q;

  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dirs.size(); i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

      if (!visited[nx][ny] && board[nx][ny] != 0) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}

void meltGlacier() {
  vector<vector<int>> copyBoard(N, vector<int>(M, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int waterCnt = 0;

      for (int d = 0; d < dirs.size(); d++) {
        int nx = i + dirs[d].first;
        int ny = j + dirs[d].second;

        if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || board[nx][ny] == 0)
          waterCnt++;
      }

      copyBoard[i][j] = board[i][j] < waterCnt ? 0 : board[i][j] - waterCnt;
    }
  }

  board = copyBoard;
}
