#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX_SIZE 101
#define INIT_SIZE 3

typedef pair<int, int> pii;

vector<vector<int>> matrix;
vector<pii> targetValue;
vector<int> numCnt;
int R, C, K;

void fastIO();
void initData();
int getMinSecond();
int executeSorting(int row, int col);

int main() {
  fastIO();

  initData();

  cout << getMinSecond() << endl;

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> R >> C >> K;

  matrix = vector<vector<int>>(MAX_SIZE, vector<int>(MAX_SIZE, 0));

  for (int i = 1; i <= INIT_SIZE; i++) {
    for (int j = 1; j <= INIT_SIZE; j++) {
      cin >> matrix[i][j];
    }
  }
}

int getMinSecond() {
  int second = -1;
  int row = INIT_SIZE;
  int col = INIT_SIZE;

  while (++second < MAX_SIZE) {
    if (matrix[R][C] == K) return second;
    if (second >= 100) break;

    if (row >= col)
      col = executeSorting(row, col);
    else
      row = executeSorting(row, col);
  }

  return -1;
}

int executeSorting(int row, int col) {
  bool isRow = row >= col ? true : false;
  int maxSize = 0;

  for (int i = 1; i <= (isRow ? row : col); i++) {
    numCnt = vector<int>(MAX_SIZE, 0);
    for (int j = 1; j <= (isRow ? col : row); j++) {
      if (isRow)
        numCnt[matrix[i][j]]++;
      else
        numCnt[matrix[j][i]]++;
    }

    for (int j = 1; j < MAX_SIZE; j++) {
      if (numCnt[j] == 0) continue;

      targetValue.push_back({j, numCnt[j]});
    }

    sort(targetValue.begin(), targetValue.end(), [](pii a, pii b) {
      return a.second != b.second ? a.second < b.second : a.first < b.first;
    });

    for (int j = 1; j <= (isRow ? col : row); j++) {
      if (isRow)
        matrix[i][j] = 0;
      else
        matrix[j][i] = 0;
    }

    int idx = 0;
    for (int j = 0; j < targetValue.size(); j++) {
      if (idx >= 100) break;
      if (isRow) {
        matrix[i][++idx] = targetValue[j].first;
        matrix[i][++idx] = targetValue[j].second;
      } else {
        matrix[++idx][i] = targetValue[j].first;
        matrix[++idx][i] = targetValue[j].second;
      }
    }
    maxSize = idx > maxSize ? idx : maxSize;
    targetValue.clear();
  }

  return maxSize;
}
