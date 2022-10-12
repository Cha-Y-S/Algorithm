#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define MIN(X, Y) (X > Y ? Y : X)

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pii> dirs;
int N, label, res;

void fast_io();
void init_data();
void make_shortest_bridge();
void classify_island();
void do_labeling(int x, int y, int label);
int get_shortest_bridge_length(int label);

int main() {
  fast_io();

  init_data();

  make_shortest_bridge();

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void init_data() {
  cin >> N;

  matrix = vector<vector<int>>(N, vector<int>(N));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = 10'001;
  label = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];

      if (matrix[i][j] == 1) {
        matrix[i][j] = -1;
      }
    }
  }
}

void make_shortest_bridge() {
  classify_island();

  for (int i = 1; i < label; i++) {
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    int length = get_shortest_bridge_length(i);
    res = MIN(res, length);
  }

  cout << res << endl;
}

void classify_island() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] == -1) {
        do_labeling(i, j, label++);
      }
    }
  }
}

void do_labeling(int x, int y, int label) {
  queue<pii> q;

  q.push({x, y});
  matrix[x][y] = label;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dirs.size(); i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

      if (matrix[nx][ny] != -1) continue;

      matrix[nx][ny] = label;
      q.push({nx, ny});
    }
  }
}

int get_shortest_bridge_length(int label) {
  queue<pii> q;
  int length = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] == label) {
        visited[i][j] = true;
        q.push({i, j});
      }
    }
  }

  while (!q.empty()) {
    int queue_size = q.size();

    for (int k = 0; k < queue_size; k++) {
      int cx = q.front().first;
      int cy = q.front().second;

      q.pop();

      for (int i = 0; i < dirs.size(); i++) {
        int nx = cx + dirs[i].first;
        int ny = cy + dirs[i].second;

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if (matrix[nx][ny] != 0 && matrix[nx][ny] != label)
          return length;
        else if (matrix[nx][ny] == 0 && !visited[nx][ny]) {
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }

    length++;
  }
}
