#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<string, int> psi;

map<string, int> enroll;
vector<psi> res;
string sid;
int K, L;

int cmp(psi a, psi b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> K >> L;

  for (int i = 0; i < L; i++) {
    cin >> sid;

    enroll[sid] = i;
  }

  for (psi p : enroll) {
    res.push_back(p);
  }

  sort(res.begin(), res.end(), cmp);

  for (int i = 0; i < res.size(); i++) {
    if (K--) {
      cout << res[i].first << endl;
    } else {
      break;
    }
  }

  return 0;
}

int cmp(psi a, psi b) {
  return a.second < b.second;
}