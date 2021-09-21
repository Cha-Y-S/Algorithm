#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> level;
vector<int> inorder;
int k;

void getLevel(int s, int e, int l);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k;

  int size = pow(2, k) - 1;

  inorder = vector<int>(size);
  level = vector<vector<int>>(k, vector<int>(0));

  for (int i = 0; i < size; i++)
    cin >> inorder[i];

  getLevel(0, size - 1, 0);

  for (int i = 0; i < level.size(); i++) {
    for (int j = 0; j < level[i].size(); j++) {
      cout << level[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

void getLevel(int s, int e, int l) {
  if (s > e) return;

  int v = inorder[(s + e) / 2];
  int mid = (s + e) / 2;

  getLevel(s, mid - 1, l + 1);
  level[l].push_back(v);
  getLevel(mid + 1, e, l + 1);
}