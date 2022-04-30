#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> cats;
vector<int> lis;
int N, M, T, r, c;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  cin >> T;

  cats = vector<pii>(T);

  for (int i = 0; i < T; i++) {
    cin >> cats[i].first >> cats[i].second;
  }

  sort(cats.begin(), cats.end(), cmp);

  for (int i = 0; i < T; i++) {
    if (cats[i].first > N || cats[i].second > M) continue;

    if (lis.empty() || lis.back() <= cats[i].second)
      lis.push_back(cats[i].second);
    else {
      int idx = upper_bound(lis.begin(), lis.end(), cats[i].second) - lis.begin();
      lis[idx] = cats[i].second;
    }
  }

  cout << lis.size() << endl;

  return 0;
}

int cmp(pii a, pii b) {
  return a.first != b.first ? a.first < b.first : a.second < b.second;
}