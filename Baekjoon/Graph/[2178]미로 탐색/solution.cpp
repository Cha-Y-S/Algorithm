#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<vector<bool>> matrix, int dx, int dy);
bool isInMatrix(int row, int col, int x, int y);

int main() {
  vector<vector<bool>> matrix;
  int row, col;

  // Initialize variables and maze matrix based on input
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    vector<bool> input;
    for (int j = 0; j < col; j++) {
      char temp;
      cin >> temp;
      input.push_back(temp == '1' ? true : false);
    }
    matrix.push_back(input);
  }

  cout << bfs(matrix, row - 1, col - 1) << endl;

  return 0;
}

int bfs(vector<vector<bool>> matrix, int dx, int dy) {
  int answer = 0;
  vector<vector<int>> visited;
  queue<pair<int, int>> q;
  vector<pair<int, int>> dir = {make_pair(0, -1), make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0)};

  // Initialize visited matrix
  for (int i = 0; i < dx + 1; i++) {
    vector<int> temp(dy + 1, 0);
    visited.push_back(temp);
  }

  // Start at <0, 0>
  q.push(make_pair(0, 0));
  visited[0][0] = 1;

  while (!q.empty()) {
    // Current location
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      // New location
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (isInMatrix(dx, dy, nx, ny)) {
        // New location is inside on matrix
        if (!visited[nx][ny] && matrix[nx][ny]) {
          // New location can go next step
          // Store new location's total step from starting location
          q.push(make_pair(nx, ny));
          visited[nx][ny] = visited[cx][cy] + 1;
        }
      }
    }
  }

  answer = visited[dx][dy];

  return answer;
}

bool isInMatrix(int row, int col, int x, int y) {
  return (((0 <= x) && (x <= row)) && ((0 <= y) && (y <= col))) ? true : false;
}