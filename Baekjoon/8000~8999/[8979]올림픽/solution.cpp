#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

struct Nation {
  int id;
  int gold;
  int silver;
  int bronze;
};

vector<Nation> nations;
int N, K, id, gold, silver, bronze, res;

bool cmp(Nation a, Nation b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  nations = vector<Nation>(N);

  for (int i = 0; i < N; i++) {
    cin >> id >> gold >> silver >> bronze;

    nations[i].id = id;
    nations[i].gold = gold;
    nations[i].silver = silver;
    nations[i].bronze = bronze;
  }

  sort(nations.begin(), nations.end(), cmp);

  for (int i = 0; i < nations.size(); i++) {
    if (nations[i].id == K) {
      res = i;
      break;
    }
  }

  for (int i = 0; i < nations.size(); i++) {
    if (nations[i].gold == nations[res].gold &&
        nations[i].silver == nations[res].silver &&
        nations[i].bronze == nations[res].bronze) {
      cout << i + 1 << endl;
      break;
    }
  }

  return 0;
}

bool cmp(Nation a, Nation b) {
  if (a.gold != b.gold) {
    return a.gold > b.gold;
  } else {
    if (a.silver != b.silver) {
      return a.silver > b.silver;
    } else {
      return a.bronze > b.bronze;
    }
  }
}