#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define COL 3
#define MAX(X, Y) (X > Y ? X : Y)
#define MIN(X, Y) (X < Y ? X : Y)

typedef pair<int, int> pii;

vector<pii> matrix;
vector<int> dir;
int N, res_max, res_min;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  matrix = vector<pii>(COL);
  dir = {-1, 0, 1};
  res_max = 0;
  res_min = 1'000'000;

  for (int i = 0; i < COL; i++) {
    cin >> matrix[i].first;

    matrix[i].second = matrix[i].first;
  }

  for (int i = 0; i < N - 1; i++) {
    vector<pii> temp(COL);

    for (int j = 0; j < COL; j++) {
      cin >> temp[j].first;

      temp[j].second = temp[j].first;

      int prev_max = 0, prev_min = 1'000'000;
      for (int k = 0; k < dir.size(); k++) {
        int py = j + dir[k];

        if (py < 0 || py >= COL) continue;

        prev_max = MAX(matrix[py].first, prev_max);
        prev_min = MIN(matrix[py].second, prev_min);
      }

      temp[j].first += prev_max;
      temp[j].second += prev_min;
    }
    matrix = temp;
  }

  for (int i = 0; i < COL; i++) {
    res_max = MAX(matrix[i].first, res_max);
    res_min = MIN(matrix[i].second, res_min);
  }

  cout << res_max << " " << res_min << endl;

  return 0;
}
