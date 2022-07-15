#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> errands;
vector<int> lis;
pii H, W, conv;
int N;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  cin >> H.first >> H.second >> W.first >> W.second;

  W.first -= H.first;
  W.second -= H.second;

  if (W.first < 0)
    conv.first = -1;
  else
    conv.first = 1;

  if (W.second < 0)
    conv.second = -1;
  else
    conv.second = 1;

  errands = vector<pii>(N);

  for (int i = 0; i < N; i++) {
    cin >> errands[i].first >> errands[i].second;

    errands[i].first -= H.first;
    errands[i].first *= conv.first;

    errands[i].second -= H.second;
    errands[i].second *= conv.second;
  }

  H = {0, 0};
  W.first *= conv.first;
  W.second *= conv.second;

  sort(errands.begin(), errands.end(), cmp);

  for (pii p : errands) {
    if (p.first < H.first || p.first > W.first) continue;
    if (p.second < H.second || p.second > W.second) continue;

    if (lis.empty() || lis.back() <= p.second)
      lis.push_back(p.second);
    else {
      int idx = upper_bound(lis.begin(), lis.end(), p.second) - lis.begin();
      lis[idx] = p.second;
    }
  }

  cout << lis.size() << endl;

  return 0;
}

int cmp(pii a, pii b) {
  return a.first != b.first ? a.first < b.first : a.second < b.second;
}