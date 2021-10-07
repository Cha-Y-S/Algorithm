#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<int>> board;
vector<pii> dir;
vector<pii> loc;
int N, M, answer;

void push_button(pii c1, pii c2, int cnt, int d);
bool is_in_board(pii c);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  board = vector<vector<int>>(N, vector<int>(M));
  dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  answer = 11;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char input;

      cin >> input;

      board[i][j] = input == 'o' ? 1 : (input == '.' ? 0 : 2);

      if (board[i][j] == 1) loc.push_back({i, j});
    }
  }

  for (int i = 0; i < 4; i++)
    push_button(loc[0], loc[1], 1, i);

  answer = answer > 10 ? -1 : answer;

  cout << answer << endl;

  return 0;
}

void push_button(pii c1, pii c2, int cnt, int d) {
  // d == 0, up    d == 1, right
  // d == 2, down  d == 3, left

  if (answer <= cnt) return;

  int nx1 = c1.first + dir[d].first;
  int ny1 = c1.second + dir[d].second;
  int nx2 = c2.first + dir[d].first;
  int ny2 = c2.second + dir[d].second;

  if (!is_in_board({nx1, ny1}) && !is_in_board({nx2, ny2}))
    return;
  else if ((is_in_board({nx1, ny1}) && !is_in_board({nx2, ny2})) || (!is_in_board({nx1, ny1}) && is_in_board({nx2, ny2}))) {
    answer = answer < cnt ? answer : cnt;
    return;
  }

  if (board[nx1][ny1] == 2) {
    nx1 = c1.first;
    ny1 = c1.second;
  }
  if (board[nx2][ny2] == 2) {
    nx2 = c2.first;
    ny2 = c2.second;
  }

  for (int i = 0; i < 4; i++)
    push_button({nx1, ny1}, {nx2, ny2}, cnt + 1, i);
}

bool is_in_board(pii c) {
  if ((0 <= c.first && c.first < N) && (0 <= c.second && c.second < M)) return true;
  return false;
}