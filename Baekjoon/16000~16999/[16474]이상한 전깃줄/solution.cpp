#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> connected;
map<int, int> l_pole, r_pole;
vector<int> lis;
int N, M, K;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int tmp;

    cin >> tmp;

    l_pole[tmp] = i;
  }

  for (int i = 0; i < M; i++) {
    int tmp;

    cin >> tmp;

    r_pole[tmp] = i;
  }

  cin >> K;

  connected = vector<pii>(K);

  for (int i = 0; i < K; i++) {
    int tmp1, tmp2;

    cin >> tmp1 >> tmp2;

    connected[i] = {l_pole[tmp1], r_pole[tmp2]};
  }

  sort(connected.begin(), connected.end(), cmp);

  for (int i = 0; i < K; i++) {
    int idx = lower_bound(lis.begin(), lis.end(), connected[i].second) - lis.begin();

    if (idx == lis.size())
      lis.push_back(connected[i].second);
    else
      lis[idx] = connected[i].second;
  }

  cout << K - lis.size() << endl;

  return 0;
}

int cmp(pii a, pii b) {
  return a.first != b.first ? a.first < b.first : a.second > b.second;
}