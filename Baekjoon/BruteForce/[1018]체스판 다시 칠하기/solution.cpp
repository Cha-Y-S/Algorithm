#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

#define COLOR(x) (x == 'B' ? 1 : 0)

using namespace std;

int getBlackCount(vector<vector<int>> chess);
int getWhitecount(vector<vector<int>> chess);

int main() {
  vector<vector<int>> input;
  vector<vector<int>> chess;
  string row;
  int answer = INT_MAX;

  int n, m;

  cin >> n >> m;

  // Change input's alphabet into number
  for (int i = 0; i < n; i++) {
    cin >> row;
    vector<int> temp;

    for (int j = 0; j < row.size(); j++)
      temp.push_back(COLOR(row[j]));

    input.push_back(temp);
  }

  for (int i = 0; i <= input.size() - 8; i++) {
    for (int j = 0; j <= input[i].size() - 8; j++) {
      // Divide input into 8 * 8 chess board
      for (int row = i; row < i + 8; row++) {
        vector<int> temp;
        for (int col = j; col < j + 8; col++) {
          temp.push_back(input[row][col]);
        }
        chess.push_back(temp);
      }

      // Get number of rectangles that need to be repainted
      int diff = min(getBlackCount(chess), getWhitecount(chess));

      // Get minimum of rectangles repainted
      answer = answer > diff ? diff : answer;

      // clear 8 * 8 chess board
      chess.clear();
    }
  }

  cout << answer << endl;

  return 0;
}

int getBlackCount(vector<vector<int>> chess) {
  vector<vector<int>> black = {{1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1}};

  int cnt = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cnt = chess[i][j] != black[i][j] ? cnt + 1 : cnt;
    }
  }

  return cnt;
}

int getWhitecount(vector<vector<int>> chess) {
  vector<vector<int>> white = {{0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1, 0, 1},
                               {1, 0, 1, 0, 1, 0, 1, 0}};
  int cnt = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cnt = chess[i][j] != white[i][j] ? cnt + 1 : cnt;
    }
  }

  return cnt;
}