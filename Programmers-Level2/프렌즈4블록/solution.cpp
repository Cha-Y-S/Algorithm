#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
  int answer = 0;
  bool isRemoved = true;

  // Looping until there are no block that can be removed
  while (isRemoved) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    isRemoved = false;

    for (int i = 0; i < m - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (!board[i][j]) continue;
        // Check whether 2 x 2 block can be made based on board[i][j]
        if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i][j + 1]) && (board[i][j] == board[i + 1][j + 1])) {
          vector<pair<int, int>> dir = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
          for (int k = 0; k < dir.size(); k++)
            visited[i + dir[k].first][j + dir[k].second] = true;
          isRemoved = true;
        }
      }
    }

    // Remove block of 2 x 2 that can be removed and Drop that block
    for (int i = 0; i < visited.size(); i++) {
      for (int j = 0; j < visited[i].size(); j++) {
        if (visited[i][j]) {
          answer++;
          for (int k = i - 1; k >= 0; k--) {
            board[k + 1][j] = board[k][j];
            board[k][j] = 0;
          }
        }
      }
    }
  }

  return answer;
}