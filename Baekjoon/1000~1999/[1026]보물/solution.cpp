#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> a;
  vector<int> b;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;

    cin >> x;

    a.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    int x;

    cin >> x;

    b.push_back(x);
  }

  sort(a.begin(), a.end());

  sort(b.begin(), b.end(), greater<int>());

  int dot = 0;
  for (int i = 0; i < n; i++) {
    dot += a[i] * b[i];
  }

  cout << dot << endl;

  return 0;
}