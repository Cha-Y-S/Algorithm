#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  vector<vector<int>> cBoard;
  vector<int> basket;

  for (int i = 0; i < board.size(); i++) {
    vector<int> temp;
    for (int j = 0; j < board.size(); j++) {
      temp.push_back(0);
    }
    cBoard.push_back(temp);
  }

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cBoard[j][board.size() - 1 - i] = board[i][j];
    }
  }

  for (int i = 0; i < cBoard.size(); i++) {
    for (int j = 0; j < cBoard[i].size(); j++) {
      if (cBoard[i][j] == 0) cBoard[i].erase(cBoard[i].begin() + j--);
    }
  }

  int prev = 0;
  for (int i = 0; i < moves.size(); i++) {
    if (cBoard[moves[i] - 1].empty()) continue;

    int select = cBoard[moves[i] - 1][cBoard[moves[i] - 1].size() - 1];

    cBoard[moves[i] - 1].pop_back();
    if (select == prev) {
      answer += 2;
      if (basket.empty()) {
        prev = 0;
      } else {
        basket.pop_back();
        prev = basket[basket.size() - 1];
      }
    } else {
      basket.push_back(select);
      prev = select;
    }
  }

  return answer;
}