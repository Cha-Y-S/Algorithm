#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<vector<bool>> matrix);
int bfs(vector<vector<bool>> matrix, vector<bool> &visited, int v);

int main() {
  vector<vector<bool>> matrix;
  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    vector<bool> input(n, false);
    matrix.push_back(input);
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    matrix[u - 1][v - 1] = true;
    matrix[v - 1][u - 1] = true;
  }

  cout << solution(matrix) << endl;

  return 0;
}

int solution(vector<vector<bool>> matrix) {
  int answer = 0;
  vector<bool> visited(matrix.size(), false);
  vector<int> complex;

  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      complex.push_back(bfs(matrix, visited, i));
    }
  }

  answer = complex.size();

  return answer;
}

int bfs(vector<vector<bool>> matrix, vector<bool> &visited, int v) {
  int count = 0;
  queue<int> q;

  q.push(v);
  visited[v] = true;

  while (!q.empty()) {
    int u = q.front();

    q.pop();

    for (int i = 0; i < matrix[u].size(); i++) {
      if (matrix[u][i] && !visited[i]) {
        q.push(i);
        visited[i] = true;
        count++;
      }
    }
  }

  return count;
}