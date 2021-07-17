#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> matrix);
int solution(vector<vector<bool>> matrix);

int main() {
  vector<vector<bool>> matrix;
  int computer, network;

  cin >> computer >> network;

  // Initialize matrix
  for (int i = 0; i < computer; i++) {
    vector<bool> temp(computer, false);
    matrix.push_back(temp);
  }

  for (int i = 0; i < network; i++) {
    int c1, c2;
    cin >> c1 >> c2;

    matrix[c1 - 1][c2 - 1] = true;
    matrix[c2 - 1][c1 - 1] = true;
  }

  cout << solution(matrix) << endl;

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
  vector<bool> visited(matrix.size(), false);
  queue<int> q;

  visited[0] = true;
  q.push(0);

  while (!q.empty()) {
    int com = q.front();
    q.pop();

    for (int i = 0; i < matrix[com].size(); i++) {
      if (matrix[com][i] && !visited[i]) {
        q.push(i);
        visited[i] = true;

        answer++;
      }
    }
  }

  return answer;
}