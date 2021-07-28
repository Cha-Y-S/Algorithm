#include "solution.h"

using namespace std;

int main() {
  vector<vector<int>> board;

  cout << solution(board = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << endl;

  cout << solution(board = {{0, 0, 1, 1}, {1, 1, 1, 1}}) << endl;

  return 0;
}