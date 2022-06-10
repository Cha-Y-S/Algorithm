#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n";

typedef pair<int, int> pii;

vector<pii> flowers, res;
vector<int> days;
int N, sm, sd, em, ed, idx, start, finish;

bool cmp(pii a, pii b) {
  return a.first != b.first ? a.first < b.first : a.second > b.second;
}

bool cmpByFinish(pii a, pii b) {
  return a.second > b.second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  idx = 0;
  start = 59;
  finish = 60;

  days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

  for (int i = 0; i < N; i++) {
    cin >> sm >> sd >> em >> ed;

    if (sm < 3) {
      sm = 3;
      sd = 1;
    }
    if (em > 11) {
      em = 12;
      ed = 1;
    }

    flowers.push_back({days[sm - 1] + sd, days[em - 1] + ed});
  }

  sort(flowers.begin(), flowers.end(), cmp);

  vector<pii> targets;

  while (idx < N && finish < 335) {
    if (flowers[idx].first > finish) {
      break;
    }

    while (flowers[idx].first <= finish && idx < N) {
      targets.push_back(flowers[idx++]);
    }

    sort(targets.begin(), targets.end(), cmpByFinish);

    res.push_back(targets[0]);

    start = targets[0].first;
    finish = targets[0].second;

    targets.clear();
  }

  if (finish < 335) {
    cout << 0 << endl;
  } else {
    cout << res.size() << endl;
  }

  return 0;
}