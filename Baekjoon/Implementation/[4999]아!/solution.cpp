#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string J, D;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> J >> D;

  cout << (J.size() >= D.size() ? "go" : "no") << endl;

  return 0;
}