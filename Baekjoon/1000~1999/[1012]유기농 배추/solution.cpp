#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> matrix);
int solution(vector<vector<bool>> matrix);
int bfs(vector<vector<bool>> matrix, vector<vector<bool>>& visited, int x, int y);

int main() {
  int tCase;

  cin >> tCase;

  for (int i = 0; i < tCase; i++) {
    int col, row, edge;
    cin >> col >> row >> edge;

    vector<vector<bool>> matrix;

    // Initialize matrix;
    for (int j = 0; j < row; j++) {
      vector<bool> input(col, false);
      matrix.push_back(input);
    }

    for (int j = 0; j < edge; j++) {
      int x, y;
      cin >> x >> y;

      matrix[y][x] = true;
    }

    // printMatrix(matrix);
    cout << solution(matrix) << endl;
  }
  return 0;
}

template <typename T>
void printMatrix(vector<vector<T>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int solution(vector<vector<bool>> matrix) {
  int answer = 0;
  vector<vector<bool>> visited;
  vector<int> cluster;

  // Initialize visited matrix;
  for (int i = 0; i < matrix.size(); i++) {
    vector<bool> temp(matrix[i].size(), false);
    visited.push_back(temp);
  }

  for (int i = 0; i < visited.size(); i++) {
    for (int j = 0; j < visited[i].size(); j++) {
      if (!visited[i][j] & matrix[i][j]) {
        cluster.push_back(bfs(matrix, visited, i, j));
      }
    }
  }

  answer = cluster.size();

  return answer;
}

int bfs(vector<vector<bool>> matrix, vector<vector<bool>>& visited, int x, int y) {
  int cnt = 0;
  vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
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

      if (((0 <= nx) && (nx < matrix.size())) && ((0 <= ny) && (ny < matrix[nx].size()))) {
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