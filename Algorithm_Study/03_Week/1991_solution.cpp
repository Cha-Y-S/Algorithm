#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<char>> tree;

void preorder(char v);
void inorder(char v);
void postorder(char v);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  tree = vector<vector<char>>(n, vector<char>(2, 0));

  for (int i = 0; i < n; i++) {
    char root, left, right;

    cin >> root >> left >> right;

    tree[root - 'A'][0] = left;
    tree[root - 'A'][1] = right;
  }

  preorder('A');
  cout << endl;
  inorder('A');
  cout << endl;
  postorder('A');
  cout << endl;

  return 0;
}

void preorder(char v) {
  if (v == '.') return;
  cout << v;
  preorder(tree[v - 'A'][0]);
  preorder(tree[v - 'A'][1]);
}

void inorder(char v) {
  if (v == '.') return;
  inorder(tree[v - 'A'][0]);
  cout << v;
  inorder(tree[v - 'A'][1]);
}

void postorder(char v) {
  if (v == '.') return;
  postorder(tree[v - 'A'][0]);
  postorder(tree[v - 'A'][1]);
  cout << v;
}