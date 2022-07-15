#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
int n = 1;

void changePreToPost(int v, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  tree = vector<int>(10001, 0);

  while (cin >> tree[n])
    n++;

  changePreToPost(1, n - 1);

  return 0;
}

void changePreToPost(int v, int b) {
  int sub = v + 1;

  while (sub <= b && tree[sub] < tree[v])
    sub++;

  int left = v + 1;
  if (left <= sub - 1)
    changePreToPost(left, sub - 1);

  if (sub <= b)
    changePreToPost(sub, b);

  cout << tree[v] << endl;
}