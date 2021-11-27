#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> ds;
int N, M;

void union_set(int a, int b);
int find_set(int a);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  ds = vector<int>(N + 1);

  for (int i = 1; i <= N; i++)
    ds[i] = i;

  for (int i = 0; i < M; i++) {
    int q, a, b;

    cin >> q >> a >> b;

    if (q == 0)
      union_set(a, b);
    else
      cout << (find_set(a) == find_set(b) ? "YES" : "NO") << endl;
  }

  for (int i = 1; i <= N; i++)
    cout << ds[i] << " ";
  cout << endl;

  return 0;
}

void union_set(int a, int b) {
  int sa = find_set(a);
  int sb = find_set(b);

  if (sa == sb) return;

  ds[sb] = sa;
}

int find_set(int a) {
  if (ds[a] == a) return a;
  return ds[a] = find_set(ds[a]);
}
