#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
  int answer = 1234;
  int max_num = board[0][0];

  for (int i = 1; i < board.size(); i++) {
    for (int j = 1; j < board[i].size(); j++) {
      if (board[i][j]) {
        board[i][j] = 1 + min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]});
        max_num = max(max_num, board[i][j]);
      }
    }
  }

  answer = max_num * max_num;

  return answer;
}