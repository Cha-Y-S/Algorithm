#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"
#define MIN(X, Y) (X > Y ? Y : X)

typedef pair<int, int> pii;

void fastIo();
void initData();
int getPopulationMinDiff();
bool canDivideDistrict(int x, int y, int d1, int d2);
void divideElectionDistrict(int x, int y, int d1, int d2);
int getPopulationDiff();

vector<vector<int>> A, labeled;
int N;

int main() {
  fastIo();

  initData();

  cout << getPopulationMinDiff() << endl;

  return 0;
}

void fastIo() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> N;

  A = vector<vector<int>>(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
}

int getPopulationMinDiff() {
  int result = 987'654'321;

  for (int x = 0; x < N; x++) {
    for (int y = 1; y < N; y++) {
      for (int d1 = 1; d1 <= y + 1; d1++) {
        for (int d2 = 1; d2 < N - y; d2++) {
          if (canDivideDistrict(x, y, d1, d2)) {
            divideElectionDistrict(x, y, d1, d2);

            int diff = getPopulationDiff();

            result = MIN(result, diff);
          }
        }
      }
    }
  }

  return result;
}

bool canDivideDistrict(int x, int y, int d1, int d2) {
  if (x + d1 >= N || y - d1 < 0) return false;
  if (x + d2 >= N || y + d2 >= N) return false;
  if (x + d1 + d2 >= N || y - d1 + d2 >= N) return false;
  if (x + d1 + d2 >= N || y - d1 + d2 < 0) return false;

  return true;
}

void divideElectionDistrict(int x, int y, int d1, int d2) {
  vector<pii> vertexs = {
      {x, y}, {x + d1, y - d1}, {x + d2, y + d2}, {x + d1 + d2, y - d1 + d2}};
  int yLimit = 0;

  labeled = vector<vector<int>>(N, vector<int>(N, 5));

  for (int i = 0; i < vertexs[1].first; i++) {
    if (i >= vertexs[0].first) yLimit++;
    for (int j = 0; j <= vertexs[0].second - yLimit; j++) {
      labeled[i][j] = 1;
    }
  }

  yLimit = 0;
  for (int i = 0; i <= vertexs[2].first; i++) {
    if (i > vertexs[0].first) yLimit++;
    for (int j = vertexs[0].second + yLimit + 1; j < N; j++) {
      labeled[i][j] = 2;
    }
  }

  yLimit = 0;
  for (int i = N - 1; i >= vertexs[1].first; i--) {
    if (i < vertexs[3].first) yLimit++;
    for (int j = 0; j < vertexs[3].second - yLimit; j++) {
      labeled[i][j] = 3;
    }
  }

  yLimit = 0;
  for (int i = N - 1; i > vertexs[2].first; i--) {
    if (i <= vertexs[3].first) yLimit++;
    for (int j = vertexs[3].second + yLimit; j < N; j++) {
      labeled[i][j] = 4;
    }
  }
}

int getPopulationDiff() {
  vector<int> population = {0, 0, 0, 0, 0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      population[labeled[i][j] - 1] += A[i][j];
    }
  }

  sort(population.begin(), population.end());

  return population[4] - population[0];
}
