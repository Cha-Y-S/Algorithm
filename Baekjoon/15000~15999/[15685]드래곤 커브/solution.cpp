#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX_SIZE 101

typedef pair<int, int> pii;

void fastIO();
void initData();
int getFitSquareCount();
void drawDragonCurve();
int getSquareCount();

vector<vector<bool>> matrix;
vector<pii> dirs;
vector<int> info;
int N, x, y, d, g;

int main() {
  fastIO();

  initData();

  cout << getFitSquareCount() << endl;

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> N;

  matrix = vector<vector<bool>>(MAX_SIZE, vector<bool>(MAX_SIZE, false));
  dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
}

int getFitSquareCount() {
  for (int i = 0; i < N; i++) {
    info.clear();

    cin >> y >> x >> d >> g;

    matrix[x][y] = true;
    x += dirs[d].first;
    y += dirs[d].second;
    matrix[x][y] = true;

    info.push_back(d);

    for (int j = 0; j < g; j++) {
      drawDragonCurve();
    }
  }

  return getSquareCount();
}

void drawDragonCurve() {
  int size = info.size();
  for (int i = size - 1; i >= 0; i--) {
    int dirIdx = (info[i] + 1) % 4;

    x += dirs[dirIdx].first;
    y += dirs[dirIdx].second;
    matrix[x][y] = true;

    info.push_back(dirIdx);
  }
}

int getSquareCount() {
  int result = 0;

  for (int i = 0; i < MAX_SIZE - 1; i++) {
    for (int j = 0; j < MAX_SIZE - 1; j++) {
      if (matrix[i][j] && matrix[i + 1][j] && matrix[i][j + 1] &&
          matrix[i + 1][j + 1]) {
        result++;
      }
    }
  }

  return result;
}
