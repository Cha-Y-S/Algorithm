#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix);

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
  }

  cout << solution(matrix) << endl;

  return 0;
}

int solution(vector<vector<int>> matrix) {
}