#include <iostream>
#include <set>

using namespace std;

#define endl "\n"

set<int> s;
int N, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> num;

    s.insert(num);
  }

  for (int n : s) {
    cout << n << " ";
  }
  cout << endl;

  return 0;
}