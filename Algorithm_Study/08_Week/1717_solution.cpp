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

  ds = vector<int>(N);

  for (int i = 0; i < N; i++)
    ds[i] = i;

  for (int i = 0; i < M; i++) {
    int q, a, b;

    cin >> q >> a >> b;

    if (q == 0)
      union_set(a - 1, b - 1);
    else
      cout << (find_set(a - 1) == find_set(b - 1) ? "YES" : "NO") << endl;
  }
}

void union_set(int a, int b) {
  int sa = find_set(a);
  int sb = find_set(b);

  if (sa == sb) return;

  ds[sb] = sa;
}

int find(int a) {
  if (ds[a] == a) return a;
  return find(arr[a]);
}
