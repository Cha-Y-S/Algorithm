#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> par;
vector<int> cnt;
vector<int> res;
int N, M;

void print_info();
void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  par = vector<vector<int>>(N);
  cnt = vector<int>(N, 0);

  for (int i = 0; i < M; i++) {
    vector<int> input;
    int num;

    cin >> num;

    input = vector<int>(num);

    for (int j = 0; j < num; j++)
      cin >> input[j];

    for (int j = 1; j < num; j++) {
      int p = input[j] - 1;
      int c = input[j - 1] - 1;

      par[c].push_back(p);
      cnt[p]++;
    }
  }

  topological_sort();

  print_res();

  return 0;
}

void print_info() {
  cout << "===== parent =====" << endl;
  for (int i = 0; i < par.size(); i++) {
    cout << i << ": ";
    for (int j = 0; j < par[i].size(); j++) {
      cout << par[i][j] << " ";
    }
    cout << endl;
  }

  cout << "===== cnt =====" << endl;
  for (int i = 0; i < cnt.size(); i++)
    cout << cnt[i] << " ";
  cout << endl;
}

void topological_sort() {
  queue<int> q;
  vector<bool> visited(N, false);

  for (int i = 0; i < cnt.size(); i++) {
    if (cnt[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();

    visited[cur] = true;

    q.pop();

    res.push_back(cur);

    for (int i = 0; i < par[cur].size(); i++) {
      if (--cnt[par[cur][i]] == 0) q.push(par[cur][i]);
    }
  }
  if (*min_element(visited.begin(), visited.end()) == false) {
    res.clear();
  }
}

void print_res() {
  if (res.size() == 0) cout << 0 << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i] + 1 << endl;
}