#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> world;
int N, M, B, max_h, min_h, t_answer, h_answer;

int flatting_world(int h);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> B;

  world = vector<vector<int>>(N, vector<int>(M));
  max_h = 0;
  min_h = 256;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> world[i][j];
      max_h = max_h < world[i][j] ? world[i][j] : max_h;
      min_h = min_h > world[i][j] ? world[i][j] : min_h;
    }
  }

  t_answer = 500 * 500 * 512;
  h_answer = 0;

  for (int i = min_h; i <= max_h; i++) {
    int res = flatting_world(i);

    if (res >= 0 && res <= t_answer) {
      t_answer = res;
      h_answer = i;
    }
  }

  cout << t_answer << " " << h_answer << endl;

  return 0;
}

int flatting_world(int h) {
  int h_cnt = 0, l_cnt = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (world[i][j] > h)
        h_cnt += world[i][j] - h;
      else if (world[i][j] < h)
        l_cnt += h - world[i][j];
    }
  }

  if (h_cnt == 0 && l_cnt == 0)
    return 0;

  if (l_cnt > h_cnt + B)
    return -1;

  return h_cnt * 2 + l_cnt;
}