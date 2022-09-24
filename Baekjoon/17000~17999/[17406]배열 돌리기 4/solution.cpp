#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

typedef struct {
  int row;
  int col;
  int size;
} Operation;

vector<vector<int>> original_matrix, copy_matrix;
vector<Operation> operations, operations_order;
vector<bool> selected;
vector<pii> dirs;
int N, M, K;
int dir_idx, res;

void fast_io();
void initialize_data();
void order_operations(int select_cnt);
void rotate_matrix(int sx, int sy, int ex, int ey);
int calculate_matrix_value();

int main() {
  fast_io();
  initialize_data();

  order_operations(0);

  cout << res << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initialize_data() {
  cin >> N >> M >> K;

  original_matrix = vector<vector<int>>(N, vector<int>(M));
  copy_matrix = vector<vector<int>>(N, vector<int>(M));
  operations = vector<Operation>(K);
  operations_order = vector<Operation>(K);
  selected = vector<bool>(K, false);
  dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  dir_idx = 0;
  res = 5'001;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> original_matrix[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    cin >> operations[i].row >> operations[i].col >> operations[i].size;

    operations[i].row--;
    operations[i].col--;
  }
}

void order_operations(int select_cnt) {
  if (select_cnt == K) {
    copy_matrix = original_matrix;

    for (int i = 0; i < K; i++) {
      int sx = operations_order[i].row - operations_order[i].size;
      int sy = operations_order[i].col - operations_order[i].size;
      int ex = operations_order[i].row + operations_order[i].size;
      int ey = operations_order[i].col + operations_order[i].size;

      rotate_matrix(sx, sy, ex, ey);
    }

    int temp = calculate_matrix_value();
    res = temp < res ? temp : res;
  }

  for (int i = 0; i < K; i++) {
    if (selected[i]) continue;
    selected[i] = true;
    operations_order[select_cnt] = operations[i];
    order_operations(select_cnt + 1);
    selected[i] = false;
  }
}

void rotate_matrix(int sx, int sy, int ex, int ey) {
  if (sx >= ex || sy >= ey) return;

  int start_value = copy_matrix[sx][sy];
  int cur_x = sx;
  int cur_y = sy;

  while (cur_x + dirs[dir_idx].first != sx ||
         cur_y + dirs[dir_idx].second != sy) {
    int next_x = cur_x + dirs[dir_idx].first;
    int next_y = cur_y + dirs[dir_idx].second;

    if (next_x < sx || next_y < sy || next_x > ex || next_y > ey) {
      dir_idx = (dir_idx + 1) % 4;

      continue;
    }

    copy_matrix[cur_x][cur_y] = copy_matrix[next_x][next_y];

    cur_x = next_x;
    cur_y = next_y;
  }

  copy_matrix[cur_x][cur_y] = start_value;

  rotate_matrix(sx + 1, sy + 1, ex - 1, ey - 1);
}

int calculate_matrix_value() {
  int result = 5'001;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < M; j++) {
      sum += copy_matrix[i][j];
    }
    result = result < sum ? result : sum;
  }
  return result;
}