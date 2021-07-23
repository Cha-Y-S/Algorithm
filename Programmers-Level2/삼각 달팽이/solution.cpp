#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
  vector<int> answer;
  vector<vector<int>> matrix;
  int x = 0;
  int y = 0;
  int cnt = 0;
  int max = 0;

  // Find max number
  for (int i = 0; i < n; i++) {
    max += i + 1;
  }

  // Initialize 2 dimentional matrix
  for (int i = 0; i < n; i++) {
    vector<int> temp(i + 1, 0);
    matrix.push_back(temp);
  }

  // Fill matrix
  while (cnt < max) {
    // Vertical direction
    while ((0 <= y && y < matrix.size()) && !matrix[y][x]) {
      matrix[y++][x] = ++cnt;
    }

    y -= 1;
    x += 1;

    // Horizontal direction
    while ((0 <= x && x < matrix[y].size()) && !matrix[y][x]) {
      matrix[y][x++] = ++cnt;
    }

    x -= 2;
    y -= 1;

    // Diagonal direction
    while ((0 <= y && y < matrix.size()) && (0 <= x && x < matrix[y].size()) && !matrix[y][x]) {
      matrix[y--][x--] = ++cnt;
    }
    y += 2;
    x += 1;
  }

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      answer.push_back(matrix[i][j]);
    }
  }

  return answer;
}