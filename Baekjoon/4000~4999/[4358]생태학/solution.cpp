#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

map<string, int> trees;
string tree;
int cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (getline(cin, tree)) {
    cnt++;
    trees[tree]++;
  }

  cout << fixed;
  cout.precision(4);
  for (pair<string, int> p : trees) {
    cout << p.first << " " << (double)p.second / cnt * 100 << endl;
  }

  return 0;
}