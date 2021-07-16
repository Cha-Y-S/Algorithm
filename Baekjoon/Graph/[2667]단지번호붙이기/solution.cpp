#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> matrix);
vector<int> solution(vector<vector<int>> &matrix);
int bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y);

int main() {
  int N;
  vector<vector<int>> matrix;

  cin >> N;

  // Initialize matrix and visited matrix;
  for (int i = 0; i < N; i++) {
    vector<int> input;

    for (int j = 0; j < N; j++) {
      char temp;
      cin >> temp;
      input.push_back(temp - '0');
    }
    matrix.push_back(input);
  }

  solution(matrix);

  return 0;
}

template <typename T>
void printMatrix(vector<vector<T>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

vector<int> solution(vector<vector<int>> &matrix) {
  vector<vector<bool>> visited;
  vector<int> answer;

  for (int i = 0; i < matrix.size(); i++) {
    vector<bool> temp(matrix.size(), false);
    visited.push_back(temp);
  }

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] && !visited[i][j]) {
        answer.push_back(bfs(matrix, visited, i, j));
      }
    }
  }

  sort(answer.begin(), answer.end());

  cout << answer.size() << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }

  return answer;
}

int bfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y) {
  vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
  queue<pair<int, int>> q;
  int cnt = 0;

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

      if (((0 <= nx) && (nx < matrix.size())) && ((0 <= ny) && (ny < matrix.size()))) {
        if (matrix[nx][ny] && !visited[nx][ny]) {
          visited[nx][ny] = true;
          q.push(make_pair(nx, ny));
          cnt++;
        }
      }
    }
  }

  return cnt;
}