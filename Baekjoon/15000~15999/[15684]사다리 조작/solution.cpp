#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<bool>> ladder;
int N, M, H, answer;

bool game();
void draw_line(int idx, int cnt);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> H;

  ladder = vector<vector<bool>>(H + 1, vector<bool>(N + 1, false));
  answer = 4;

  for (int i = 0; i < M; i++) {
    int x, y;

    cin >> x >> y;

    ladder[x][y] = true;
  }

  draw_line(1, 0);

  answer = answer != 4 ? answer : -1;

  cout << answer << endl;

  return 0;
}

bool game() {
  for (int i = 1; i <= N; i++) {
    int cur = i;
    for (int j = 1; j <= H; j++) {
      if (ladder[j][cur])
        cur++;
      else if (ladder[j][cur - 1])
        cur--;
    }
    if (cur != i) return false;
  }
  return true;
}

void draw_line(int idx, int cnt) {
  if (cnt >= answer) return;

  if (game()) {
    answer = answer < cnt ? answer : cnt;
    return;
  }

  for (int i = idx; i <= H; i++) {
    for (int j = 1; j < N; j++) {
      if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
      ladder[i][j] = true;
      draw_line(i, cnt + 1);
      ladder[i][j] = false;
    }
  }
}