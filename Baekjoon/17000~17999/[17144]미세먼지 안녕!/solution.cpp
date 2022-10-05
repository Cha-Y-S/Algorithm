#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define DIR_SIZE 4

typedef pair<int, int> pii;

vector<vector<int>> house, spread;
vector<pii> dirs;
int top_cleaner, bottom_cleaner;
int R, C, T, res;

void fast_io();
void init_data();
void operate_monitoring_system();
void spread_dust();
void operate_air_conditioner();
void circulate_air(int x_start, int y_start, bool direction = true);
void print_house();

int main() {
  // fast_io();

  init_data();

  operate_monitoring_system();

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void init_data() {
  cin >> R >> C >> T;

  house = vector<vector<int>>(R, vector<int>(C));
  spread = vector<vector<int>>(R, vector<int>(C, 0));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  top_cleaner = bottom_cleaner = res = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> house[i][j];

      if (house[i][j] == -1) {
        if (top_cleaner == 0) {
          top_cleaner = i;
        } else {
          bottom_cleaner = i;
        }
      } else {
        res += house[i][j];
      }
    }
  }
}

void operate_monitoring_system() {
  while (T--) {
    spread_dust();

    operate_air_conditioner();
  }

  cout << res << endl;
}

void spread_dust() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (house[i][j] == 0 || house[i][j] == -1) continue;

      int spread_cnt = 0;
      int spread_quantity = house[i][j] / 5;

      for (int k = 0; k < DIR_SIZE; k++) {
        int nx = i + dirs[k].first;
        int ny = j + dirs[k].second;

        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        if (house[nx][ny] == -1) continue;

        spread[nx][ny] += spread_quantity;
        spread_cnt++;
      }

      spread[i][j] -= (spread_cnt * spread_quantity);
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      house[i][j] += spread[i][j];
      spread[i][j] = 0;
    }
  }
}

void operate_air_conditioner() {
  res -= house[top_cleaner - 1][0];
  res -= house[bottom_cleaner + 1][0];

  circulate_air(top_cleaner - 1, 0);
  circulate_air(bottom_cleaner + 1, 0, false);
}

void circulate_air(int x_start, int y_start, bool direction) {
  int dir_idx = direction ? 0 : 2;

  int cx = x_start;
  int cy = y_start;

  while (true) {
    int nx = cx + dirs[dir_idx].first;
    int ny = cy + dirs[dir_idx].second;

    if (direction) {
      if (nx < 0 || ny < 0 || nx > top_cleaner || ny >= C) {
        dir_idx = (dir_idx + 1) % 4;
        continue;
      }
    } else {
      if (nx < bottom_cleaner || ny < 0 || nx >= R || ny >= C) {
        dir_idx = (dir_idx + 3) % 4;
        continue;
      }
    }

    if (house[nx][ny] == -1) {
      house[cx][cy] = 0;
      break;
    }

    house[cx][cy] = house[nx][ny];
    cx = nx;
    cy = ny;
  }
}
