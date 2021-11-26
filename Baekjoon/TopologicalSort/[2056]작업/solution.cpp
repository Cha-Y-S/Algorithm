#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> par;
vector<int> cnt;
vector<int> working;
vector<int> res;
int N;

void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  par = vector<vector<int>>(N);
  cnt = vector<int>(N, 0);
  working = vector<int>(N);
  res = vector<int>(N);

  for (int i = 0; i < N; i++) {
    int t, w_num;

    cin >> t >> w_num;

    working[i] = t;

    for (int j = 0; j < w_num; j++) {
      int c;

      cin >> c;

      par[i].push_back(c - 1);
      cnt[c - 1]++;
    }
  }

  topological_sort();

  print_res();

  return 0;
}

void topological_sort() {
  queue<int> q;

  for (int i = 0; i < cnt.size(); i++) {
    if (cnt[i] == 0) {
      q.push(i);
      res[i] = working[i];
    }
  }

  while (!q.empty()) {
    int cur = q.front();

    q.pop();

    for (int i = 0; i < par[cur].size(); i++) {
      int next = par[cur][i];

      res[next] = max(res[next], res[cur] + working[next]);
      if (--cnt[next] == 0) q.push(next);
    }
  }
}

void print_res() {
  cout << *max_element(res.begin(), res.end()) << endl;
}