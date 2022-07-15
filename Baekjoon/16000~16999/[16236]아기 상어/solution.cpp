#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

pair<pii, int> shark;
vector<pair<int, pii>> fish;
vector<vector<int>> matrix;
vector<pii> dir;
int N, res, eat_cnt;

void bfs(int x, int y);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  matrix = vector<vector<int>>(N, vector<int>(N));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  res = eat_cnt = 0;
  shark.second = 2;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];

      if (matrix[i][j] == 9) {
        matrix[i][j] = 0;
        shark.first.first = i;
        shark.first.second = j;
      }
    }
  }

  while (true) {
    fish.clear();
    bfs(shark.first.first, shark.first.second);

    if (fish.empty())
      break;
    else {
      sort(fish.begin(), fish.end());
      eat_cnt++;
      res += fish[0].first;
      matrix[fish[0].second.first][fish[0].second.second] = 0;
      shark.first.first = fish[0].second.first;
      shark.first.second = fish[0].second.second;
      if (shark.second == eat_cnt) {
        shark.second++;
        eat_cnt = 0;
      }
    }
  }

  cout << res << endl;

  return 0;
}

void bfs(int x, int y) {
  vector<vector<int>> visited(N, vector<int>(N, 0));
  queue<pii> q;
  int eat_dist = INT_MAX;

  q.push({x, y});

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < N) && (0 <= ny && ny < N)) {
        if (visited[nx][ny] == 0 && shark.second >= matrix[nx][ny]) {
          visited[nx][ny] = visited[cx][cy] + 1;

          if (matrix[nx][ny] > 0 && matrix[nx][ny] < shark.second) {
            if (eat_dist >= visited[nx][ny]) {
              eat_dist = visited[nx][ny];
              fish.push_back({eat_dist, {nx, ny}});
            }
          }

          q.push({nx, ny});
        }
      }
    }
  }
}