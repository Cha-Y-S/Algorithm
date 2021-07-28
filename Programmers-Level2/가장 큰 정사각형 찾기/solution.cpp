#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
  int answer = 1234;

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return answer;
}