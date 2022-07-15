#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<char, int> pci;
typedef pair<double, char> pdc;

vector<pci> staff;
vector<pci> res;
vector<pdc> s;
map<char, int> candidates;
int X, N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> X >> N;

  staff = vector<pci>(N);

  for (int i = 0; i < N; i++) {
    cin >> staff[i].first >> staff[i].second;

    if ((double)staff[i].second / X * 100 >= 5) {
      candidates[staff[i].first] = 0;

      for (int j = 0; j < 14; j++) {
        s.push_back({(double)staff[i].second / (j + 1), staff[i].first});
      }
    }
  }

  sort(s.begin(), s.end(), greater<>());

  for (int i = 0; i < 14; i++) {
    candidates[s[i].second]++;
  }

  for (pci p : candidates) {
    res.push_back(p);
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first << " " << res[i].second << endl;
  }

  return 0;
}