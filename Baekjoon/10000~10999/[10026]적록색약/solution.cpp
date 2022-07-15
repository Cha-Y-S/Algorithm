#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> pic;
vector<vector<bool>> visited;
vector<pii> green;
vector<pii> dir;
int N, normal, blind;

void dfs(int x, int y, int color);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  pic = vector<vector<int>>(N, vector<int>(N));
  visited = vector<vector<bool>>(N, vector<bool>(N, false));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  normal = blind = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char color;

      cin >> color;

      if (color == 'R')
        pic[i][j] = 1;
      else if (color == 'G') {
        pic[i][j] = 2;
        green.push_back({i, j});
      } else
        pic[i][j] = 3;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        dfs(i, j, pic[i][j]);
        normal++;
      }
    }
  }

  visited = vector<vector<bool>>(N, vector<bool>(N, false));

  for (int i = 0; i < green.size(); i++) {
    int x = green[i].first;
    int y = green[i].second;
    pic[x][y] = 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        dfs(i, j, pic[i][j]);
        blind++;
      }
    }
  }

  cout << normal << " " << blind << endl;

  return 0;
}

void dfs(int x, int y, int color) {
  if (visited[x][y]) return;

  visited[x][y] = true;

  for (int i = 0; i < dir.size(); i++) {
    int nx = x + dir[i].first;
    int ny = y + dir[i].second;

    if ((0 <= nx && nx < N) && (0 <= ny && ny < N)) {
      if (!visited[nx][ny] && pic[nx][ny] == color)
        dfs(nx, ny, color);
    }
  }
}