#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MIN(X, Y) (X > Y ? Y : X)
#define MAX_COST 1'000'001

void fastIO();
void initData();
int getMinValue();

vector<vector<int>> color;
vector<vector<int>> house;
int N;

int main() {
  fastIO();

  initData();

  cout << getMinValue() << endl;

  return 0;
}

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void initData() {
  cin >> N;

  color = vector<vector<int>>(N + 1, vector<int>(3));

  for (int i = 1; i <= N; i++) {
    cin >> color[i][0] >> color[i][1] >> color[i][2];
  }
}

int getMinValue() {
  int res = MAX_COST;

  for (int rgb = 0; rgb <= 2; rgb++) {
    house = vector<vector<int>>(N + 1, vector<int>(3, 0));

    for (int i = 0; i <= 2; i++) {
      if (i == rgb)
        house[1][rgb] = color[1][rgb];
      else
        house[1][i] = MAX_COST;
    }

    for (int i = 2; i <= N; i++) {
      house[i][0] = color[i][0] + MIN(house[i - 1][1], house[i - 1][2]);
      house[i][1] = color[i][1] + MIN(house[i - 1][0], house[i - 1][2]);
      house[i][2] = color[i][2] + MIN(house[i - 1][0], house[i - 1][1]);
    }

    for (int i = 0; i <= 2; i++) {
      if (i != rgb) {
        res = MIN(res, house[N][i]);
      }
    }
  }

  return res;
}
