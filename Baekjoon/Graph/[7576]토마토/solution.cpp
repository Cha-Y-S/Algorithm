#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix, int row, int col);

int main() {
  vector<vector<int>> matrix;
  int row, col;

  cin >> col >> row;

  // Initialize adjacent matrix
  for (int i = 0; i < row; i++) {
    vector<int> temp(col, -1);
    for (int j = 0; j < col; j++) {
      cin >> temp[j];
    }
    matrix.push_back(temp);
  }

  cout << solution(matrix, row, col) << endl;

  return 0;
}

int solution(vector<vector<int>> matrix, int row, int col) {
  int answer = 0;
  vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
  queue<pair<int, int>> q;

  // Push into q value that is 1
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (matrix[i][j] == 1) q.push(make_pair(i, j));
    }
  }

  // BFS
  while (!q.empty()) {
    int cx = q.front().first;
    int cy = q.front().second;

    q.pop();

    for (int i = 0; i < dir.size(); i++) {
      int nx = cx + dir[i].first;
      int ny = cy + dir[i].second;

      if (((0 <= nx) && (nx < row)) && ((0 <= ny) && (ny < col))) {
        if (matrix[nx][ny] == 0) {
          matrix[nx][ny] = matrix[cx][cy] + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }

  // Find Max or 0
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (!matrix[i][j]) {
        answer = -1;
        return answer;
      }

      if (answer < matrix[i][j]) answer = matrix[i][j];
    }
  }

  answer--;

  return answer;
}