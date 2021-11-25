#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> par;
vector<int> cnt;
vector<int> res;
int N, M;

void topological_sort();
void print_res();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  par = vector<vector<int>>(N);
  cnt = vector<int>(N, 0);

  for (int i = 0; i < M; i++) {
    int A, B;

    cin >> A >> B;

    par[A - 1].push_back(B - 1);
    cnt[B - 1]++;
  }

  topological_sort();

  print_res();

  return 0;
}

void topological_sort() {
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < N; i++) {
    if (cnt[i] == 0) pq.push(i);
  }

  while (!pq.empty()) {
    int cur = pq.top();

    pq.pop();

    res.push_back(cur);

    for (int i = 0; i < par[cur].size(); i++) {
      if (--cnt[par[cur][i]] == 0) pq.push(par[cur][i]);
    }
  }
}

void print_res() {
  for (int i = 0; i < N; i++)
    cout << res[i] + 1 << " ";
  cout << endl;
}