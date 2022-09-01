#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pii> unite;
vector<pii> dirs;
int N, L, R, res;

void fast_io();
int get_population_movement_days();
int get_all_population_united_country(int x, int y);

int main() {
  fast_io();

  cin >> N >> L >> R;

  matrix = vector<vector<int>>(N, vector<int>(N));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }

  res = get_population_movement_days();

  cout << res << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int get_population_movement_days() {
  int result = 0;
  int can_combined = true;

  while (can_combined) {
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    can_combined = false;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int sum;
        if (!visited[i][j]) {
          unite.clear();
          unite.push_back({i, j});
          sum = get_all_population_united_country(i, j);
        }

        // Moving populations between countries in the union
        if (unite.size() >= 2) {
          can_combined = true;
          for (int i = 0; i < unite.size(); i++) {
            matrix[unite[i].first][unite[i].second] = sum / unite.size();
          }
        }
      }
    }
    if (can_combined) {
      result++;
    }
  }

  return result;
}

int get_all_population_united_country(int x, int y) {
  queue<pii> q;
  int result = 0;

  q.push({x, y});
  visited[x][y] = true;
  result += matrix[x][y];

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dirs.size(); i++) {
      int nx = cx + dirs[i].first;
      int ny = cy + dirs[i].second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if (visited[nx][ny]) continue;

      int diff_population = abs(matrix[cx][cy] - matrix[nx][ny]);

      if (L <= diff_population && diff_population <= R) {
        q.push({nx, ny});
        visited[nx][ny] = true;

        unite.push_back({nx, ny});
        result += matrix[nx][ny];
      }
    }
  }

  return result;
}