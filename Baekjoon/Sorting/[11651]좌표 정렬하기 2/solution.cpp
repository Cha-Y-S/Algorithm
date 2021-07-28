#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b);

int main() {
  int n;
  vector<pair<int, int>> location;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;

    cin >> x >> y;

    location.push_back(make_pair(x, y));
  }

  sort(location.begin(), location.end(), compare);

  for (int i = 0; i < location.size(); i++) {
    printf("%d %d\n", location[i].first, location[i].second);
  }

  return 0;
}

int compare(pair<int, int> a, pair<int, int> b) {
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}