#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b);

int main() {
  int n;

  cin >> n;

  vector<pair<int, int>> arr(n, make_pair(0, 0));

  for (int i = 0; i < arr.size(); i++) {
    scanf("%d%d", &arr[i].first, &arr[i].second);
  }

  sort(arr.begin(), arr.end(), compare);

  for (int i = 0; i < arr.size(); i++) {
    printf("%d %d\n", arr[i].first, arr[i].second);
  }

  return 0;
}

int compare(pair<int, int> a, pair<int, int> b) {
  return a.first != b.first ? a.first < b.first : a.second < b.second;
}
