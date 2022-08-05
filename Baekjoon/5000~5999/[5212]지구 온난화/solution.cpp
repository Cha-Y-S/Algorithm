#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<vector<bool>> world, res;
vector<pii> dirs;
int R, C, min_x, min_y, max_x, max_y;

void simulate_after_50_year();
void check_after_50_year();
void print_after_50_year();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;

  world = vector<vector<bool>>(R, vector<bool>(C, false));
  dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  max_x = max_y = 0;
  min_x = R;
  min_y = C;

  for (int i = 0; i < R; i++) {
    string row;

    cin >> row;

    for (int j = 0; j < C; j++) {
      world[i][j] = row[j] == '.' ? false : true;
    }
  }

  res = world;

  simulate_after_50_year();
  check_after_50_year();
  print_after_50_year();

  return 0;
}

void simulate_after_50_year() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!world[i][j]) continue;

      int cnt = 0;
      for (int k = 0; k < dirs.size(); k++) {
        int nx = i + dirs[k].first;
        int ny = j + dirs[k].second;

        if ((nx < 0 || ny < 0 || nx >= R || ny >= C) || !world[nx][ny]) cnt++;
      }

      if (cnt >= 3) res[i][j] = false;
    }
  }
}

void check_after_50_year() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (res[i][j]) {
        min_x = min_x < i ? min_x : i;
        min_y = min_y < j ? min_y : j;
        max_x = max_x > i ? max_x : i;
        max_y = max_y > j ? max_y : j;
      }
    }
  }
}

void print_after_50_year() {
  for (int i = min_x; i <= max_x; i++) {
    for (int j = min_y; j <= max_y; j++) {
      cout << (res[i][j] ? 'X' : '.');
    }
    cout << endl;
  }
}