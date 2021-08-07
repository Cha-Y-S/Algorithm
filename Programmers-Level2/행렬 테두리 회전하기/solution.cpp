#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rotateMatrix(vector<vector<int>> &matrix, vector<int> query);

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<int> answer;
  vector<vector<int>> matrix;

  // Initialize matrix
  for (int i = 0; i < rows; i++) {
    vector<int> row;
    for (int j = 0; j < columns; j++) {
      row.push_back(i * columns + j + 1);
    }
    matrix.push_back(row);
  }

  for (int i = 0; i < queries.size(); i++) {
    answer.push_back(rotateMatrix(matrix, queries[i]));
  }

  return answer;
}

int rotateMatrix(vector<vector<int>> &matrix, vector<int> query) {
  int x1 = query[0] - 1;
  int y1 = query[1] - 1;
  int x2 = query[2] - 1;
  int y2 = query[3] - 1;

  int result = matrix[x1][y1];
  int temp = matrix[x1][y1];

  // Rotate matrix's left side
  for (int i = x1; i < x2; i++) {
    matrix[i][y1] = matrix[i + 1][y1];
    result = result > matrix[i][y1] ? matrix[i][y1] : result;
  }

  // Rotate matrix's lower side
  for (int i = y1; i < y2; i++) {
    matrix[x2][i] = matrix[x2][i + 1];
    result = result > matrix[x2][i] ? matrix[x2][i] : result;
  }

  // Rotate matrix's right side
  for (int i = x2; i > x1; i--) {
    matrix[i][y2] = matrix[i - 1][y2];
    result = result > matrix[i][y2] ? matrix[i][y2] : result;
  }

  // Rotate matrix's upper side
  for (int i = y2; i > y1; i--) {
    matrix[x1][i] = matrix[x1][i - 1];
    result = result > matrix[x1][i] ? matrix[x1][i] : result;
  }
  matrix[x1][y1 + 1] = temp;

  return result;
}