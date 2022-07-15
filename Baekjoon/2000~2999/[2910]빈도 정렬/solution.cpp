#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define endl "\n"

map<int, int> freq;
map<int, int> order;
vector<pii> sorted;
int N, C;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> C;

  for (int i = 0; i < N; i++) {
    int tmp;

    cin >> tmp;

    freq[tmp]++;

    if (order.find(tmp) == order.end()) {
      order[tmp] = i;
    }
  }

  for (pii p : freq) {
    sorted.push_back(p);
  }

  sort(sorted.begin(), sorted.end(), cmp);

  for (int i = 0; i < sorted.size(); i++) {
    for (int j = 0; j < sorted[i].second; j++) {
      cout << sorted[i].first << " ";
    }
  }
  cout << endl;

  return 0;
}

int cmp(pii a, pii b) {
  return a.second != b.second ? b.second < a.second : order[a.first] < order[b.first];
}