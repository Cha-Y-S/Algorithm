#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void printMatrix(vector<vector<bool>> matrix);
void bfs(vector<vector<bool>> matrix, int v);
void dfs(vector<vector<bool>> matrix, int v);

int main() {
  int n, m, v;
  vector<vector<bool>> matrix;

  cin >> n >> m >> v;

  // Initialize adjacent matrix with false
  for (int i = 0; i < n; i++) {
    vector<bool> temp(n, false);
    matrix.push_back(temp);
  }

  // Assign adjacent matrix with input value
  for (int i = 0; i < m; i++) {
    int v1, v2;

    cin >> v1 >> v2;

    matrix[v1 - 1][v2 - 1] = true;
    matrix[v2 - 1][v1 - 1] = true;
  }

  dfs(matrix, v - 1);

  bfs(matrix, v - 1);

  return 0;
}

void dfs(vector<vector<bool>> matrix, int v) {
  vector<bool> visited(matrix.size(), false);
  stack<int> s;

  s.push(v);

  while (!s.empty()) {
    int top = s.top();
    s.pop();

    if (visited[top]) {
      continue;
    }

    visited[top] = true;

    cout << top + 1 << " ";

    for (int i = matrix.size() - 1; i > -1; i--) {
      if (matrix[top][i] && !visited[i]) s.push(i);
    }
  }

  cout << endl;
}

void bfs(vector<vector<bool>> matrix, int v) {
  vector<bool> visited(matrix.size(), false);
  queue<int> q;

  q.push(v);
  visited[v] = true;

  while (!q.empty()) {
    int front = q.front();
    q.pop();

    cout << front + 1 << " ";

    for (int i = 0; i < matrix.size(); i++) {
      if (!visited[i] && matrix[front][i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }

  cout << endl;
}

void printMatrix(vector<vector<bool>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] ? "0" : "1";
      cout << " ";
    }
    cout << endl;
  }
}