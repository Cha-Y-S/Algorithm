#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> board;
vector<vector<int>> filled;
vector<pii> empties;
bool done = false;

void print_board();
void fill_with_number(int idx);
bool possible_located(pii cur, int value);
pii get_area(pii cur);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  board = vector<vector<int>>(9, vector<int>(9));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];

      if (board[i][j] == 0)
        empties.push_back({i, j});
    }
  }

  fill_with_number(0);

  print_board();

  return 0;
}

void print_board() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
}

void fill_with_number(int idx) {
  if (idx == empties.size()) {
    done = true;
    return;
  }

  for (int i = 1; i < 10; i++) {
    int cx = empties[idx].first;
    int cy = empties[idx].second;

    if (possible_located({cx, cy}, i)) {
      board[cx][cy] = i;
      fill_with_number(idx + 1);
      if (done) break;
      board[cx][cy] = 0;
    }
  }
}

bool possible_located(pii cur, int value) {
  bool result = true;

  int cx = cur.first;
  int cy = cur.second;

  // Check horizontal
  for (int i = 0; i < 9; i++) {
    if (board[cx][i] == value) result = false;
  }

  if (!result) return result;

  // Check vertical
  for (int i = 0; i < 9; i++) {
    if (board[i][cy] == value) result = false;
  }

  if (!result) return result;

  // Check area
  pii area = get_area(cur);

  for (int i = area.first * 3; i < area.first * 3 + 3; i++) {
    for (int j = area.second * 3; j < area.second * 3 + 3; j++) {
      if (board[i][j] == value) result = false;
    }
  }

  return result;
}

pii get_area(pii cur) {
  return {cur.first / 3, cur.second / 3};
}