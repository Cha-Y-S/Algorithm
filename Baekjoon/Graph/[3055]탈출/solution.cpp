#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string bfs(vector<vector<int>> forest, pair<int, int> s, pair<int, int> d, vector<pair<int, int>> w);
void printMatrix(vector<vector<int>> matrix);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r, c;

  cin >> r >> c;

  vector<vector<int>> forest(r, vector<int>(c, 0));
  vector<pair<int, int>> water;
  pair<int, int> start;
  pair<int, int> dest;

  for (int i = 0; i < r; i++) {
    string input;

    cin >> input;

    for (int j = 0; j < input.size(); j++) {
      switch (input[j]) {
        case '.':
          forest[i][j] = 0;
          break;
        case 'X':
          forest[i][j] = -1;
          break;
        case 'S':
          forest[i][j] = 0;
          start = {i, j};
          break;
        case 'D':
          forest[i][j] = -2;
          dest = {i, j};
          break;
        case '*':
          forest[i][j] = -3;
          water.push_back({i, j});
          break;
      }
    }
  }

  cout << bfs(forest, start, dest, water) << endl;

  return 0;
}

string bfs(vector<vector<int>> forest, pair<int, int> s, pair<int, int> d, vector<pair<int, int>> w) {
  string result = "KAKTUS";
  vector<vector<int>> visited = forest;
  vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  queue<pair<pair<int, int>, bool>> q;

  for (pair<int, int> p : w)
    q.push({p, false});

  q.push({s, true});

  visited[s.first][s.second] = 1;

  while (!q.empty()) {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    bool state = q.front().second;

    q.pop();

    if (state && cx == d.first && cy == d.second) {
      result = to_string(visited[cx][cy] - 1);
      break;
    }

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if ((0 <= nx && nx < forest.size()) && (0 <= ny && ny < forest[nx].size())) {
        if (state && (visited[nx][ny] == 0 || visited[nx][ny] == -2)) {
          visited[nx][ny] = visited[cx][cy] + 1;
          q.push({{nx, ny}, true});
        } else if (!state && visited[nx][ny] == 0) {
          visited[nx][ny] = -3;
          q.push({{nx, ny}, false});
        }
      }
    }
  }

  return result;
}