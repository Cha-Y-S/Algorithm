#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix);
int bfs(vector<vector<int>> matrix, vector<vector<bool>> &visited, int x, int y);

int main() {
  int w, h;

  while (cin >> w >> h && (w && h)) {
    vector<vector<int>> matrix;

    for (int i = 0; i < h; i++) {
      vector<int> temp(w, 0);
      for (int j = 0; j < w; j++) {
        cin >> temp[j];
      }
      matrix.push_back(temp);
    }

    cout << solution(matrix) << endl;
  }

  return 0;
}

int solution(vector<vector<int>> matrix) {
  int answer = 0;
  vector<vector<bool>> visited;
  vector<int> island;

  for (int i = 0; i < matrix.size(); i++) {
    vector<bool> temp(matrix[i].size(), false);
    visited.push_back(temp);
  }

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (!visited[i][j] && matrix[i][j]) {
        island.push_back(bfs(matrix, visited, i, j));
      }
    }
  }

  // Get number of islands
  answer = island.size();

  return answer;
}

// Get island's area
int bfs(vector<vector<int>> matrix, vector<vector<bool>> &visited, int x, int y) {
  int cnt = 0;
  // Check 8 directions including diagonal
  vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(-1, 1), make_pair(0, 1), make_pair(1, 1), make_pair(1, 0), make_pair(1, -1), make_pair(0, -1), make_pair(-1, -1)};
  queue<pair<int, int>> q;

  q.push(make_pair(x, y));
  visited[x][y] = true;
  cnt++;

  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;
      // Check that new location is in the map's scope
      if ((0 <= nx && nx < matrix.size()) && (0 <= ny && ny < matrix[nx].size())) {
        if (!visited[nx][ny] && matrix[nx][ny]) {
          q.push(make_pair(nx, ny));
          visited[nx][ny] = true;
          cnt++;
        }
      }
    }
  }

  return cnt;
}