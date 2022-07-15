#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> ds;
vector<int> cnt;
map<string, int> m;
string A, B;
int T, F, idx;

void union_set(int a, int b);
int find_set(int a);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> F;

    ds = vector<int>(F * 2);
    cnt = vector<int>(F * 2, 1);
    idx = 0;

    for (int i = 0; i < ds.size(); i++)
      ds[i] = i;

    for (int i = 0; i < F; i++) {
      cin >> A >> B;

      if (m.find(A) == m.end()) m[A] = idx++;
      if (m.find(B) == m.end()) m[B] = idx++;

      union_set(m[A], m[B]);

      cout << cnt[find_set(m[A])] << endl;
    }

    m.clear();
  }
}

void union_set(int a, int b) {
  int sa = find_set(a);
  int sb = find_set(b);

  if (sa == sb) return;

  cnt[sa] += cnt[sb];
  ds[sb] = sa;
}

int find_set(int a) {
  if (ds[a] == a) return a;
  return ds[a] = find_set(ds[a]);
}