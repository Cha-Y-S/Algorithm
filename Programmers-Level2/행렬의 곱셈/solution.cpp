#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
  vector<vector<int>> answer;

  int row = arr1.size();
  int col = arr2[0].size();
  int middle = arr1[0].size();

  for (int i = 0; i < row; i++) {
    vector<int> vRow;
    for (int j = 0; j < col; j++) {
      int num = 0;
      for (int k = 0; k < middle; k++) {
        num += arr1[i][k] * arr2[k][j];
      }
      vRow.push_back(num);
    }
    answer.push_back(vRow);
  }

  return answer;
}