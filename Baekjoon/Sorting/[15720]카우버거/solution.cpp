#include <algorithm>
#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

typedef pair<int, bool> pib;

vector<int> burger;
vector<int> side;
vector<int> drink;
vector<pib> total;
int B, C, D, max_size, res1, res2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> B >> C >> D;

  max_size = max({B, C, D});

  burger = vector<int>(B);
  side = vector<int>(C);
  drink = vector<int>(D);
  total = vector<pib>(max_size, {0, true});
  res1 = res2 = 0;

  for (int i = 0; i < B; i++) {
    cin >> burger[i];
  }

  for (int i = 0; i < C; i++) {
    cin >> side[i];
  }

  for (int i = 0; i < D; i++) {
    cin >> drink[i];
  }

  sort(burger.begin(), burger.end(), greater<>());
  sort(side.begin(), side.end(), greater<>());
  sort(drink.begin(), drink.end(), greater<>());

  for (int i = 0; i < max_size; i++) {
    if (i < B) {
      total[i].first += burger[i];
    } else {
      total[i].second = false;
    }
    if (i < C) {
      total[i].first += side[i];
    } else {
      total[i].second = false;
    }
    if (i < D) {
      total[i].first += drink[i];
    } else {
      total[i].second = false;
    }
  }

  for (int i = 0; i < max_size; i++) {
    res1 += total[i].first;

    if (total[i].second) {
      res2 += total[i].first * 0.9;
    } else {
      res2 += total[i].first;
    }
  }

  cout << res1 << endl;

  cout << res2 << endl;

  return 0;
}