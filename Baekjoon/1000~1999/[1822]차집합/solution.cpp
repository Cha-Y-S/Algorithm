#include <iostream>
#include <set>

using namespace std;

#define endl "\n"

set<int> s;
int A, B, num, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> A >> B;

  for (int i = 0; i < A; i++) {
    cin >> num;

    s.insert(num);
  }

  for (int i = 0; i < B; i++) {
    cin >> num;

    set<int>::iterator it = s.find(num);

    if (it == s.end())
      continue;
    else
      s.erase(it);
  }

  cout << s.size() << endl;

  for (int n : s)
    cout << n << " ";
  cout << endl;

  return 0;
}