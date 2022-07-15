#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<char>> board;
vector<bool> visited;
vector<pii> dir;
int R, C;
int answer;

void dfs(int x, int y, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;

  board = vector<vector<char>>(R, vector<char>(C));
  visited = vector<bool>(26, false);
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  answer = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++)
      cin >> board[i][j];
  }

  visited[board[0][0] - 'A'] = true;
  dfs(0, 0, 1);

  cout << answer << endl;

  return 0;
}

void dfs(int x, int y, int cnt) {
  answer = answer < cnt ? cnt : answer;

  for (int i = 0; i < dir.size(); i++) {
    int nx = x + dir[i].first;
    int ny = y + dir[i].second;

    if ((0 <= nx && nx < R) && (0 <= ny && ny < C)) {
      int next = board[nx][ny] - 'A';
      if (visited[next]) continue;
      visited[next] = true;
      dfs(nx, ny, cnt + 1);
      visited[next] = false;
    }
  }
}