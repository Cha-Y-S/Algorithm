#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> tree;
vector<vector<int>> node;
vector<int> par;
int width, level, root, max_l;

void inorder(int s, int l);
bool comp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  tree = vector<vector<int>>(n, vector<int>(2, 0));
  par = vector<int>(n, -1);
  node = vector<vector<int>>(n);

  for (int i = 0; i < n; i++) {
    int parent, left, right;

    cin >> parent >> left >> right;

    parent--;
    left = left == -1 ? -1 : left - 1;
    right = right == -1 ? -1 : right - 1;

    tree[parent][0] = left;
    tree[parent][1] = right;

    if (left != -1) par[left] = parent;
    if (right != -1) par[right] = parent;
  }

  root = 0;
  while (par[root] != -1) {
    root = par[root];
  }

  width = 0;
  inorder(root, 0);

  for (int i = 0; i < max_l; i++)
    sort(node[i].begin(), node[i].end());

  width = 0;
  level = max_l;

  for (int i = 1; i < max_l; i++) {
    int size = node[i].size();
    int w_temp = node[i][size - 1] - node[i][0];

    if (width < w_temp) {
      width = w_temp;
      level = i;
    }
  }

  if (width == 0) level = 0;

  cout << level + 1 << " " << width + 1 << endl;

  return 0;
}

void inorder(int s, int l) {
  max_l = max_l < l ? l : max_l;
  if (s == -1) return;

  inorder(tree[s][0], l + 1);
  node[l].push_back(width++);
  inorder(tree[s][1], l + 1);
}
