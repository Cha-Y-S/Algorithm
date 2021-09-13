#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> v_index;
vector<int> inorder;
vector<int> postorder;
int n;

void printPreOrder(int is, int ie, int ps, int pe);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  inorder = vector<int>(n + 1);
  postorder = vector<int>(n + 1);
  v_index = vector<int>(n + 1);

  for (int i = 1; i < n + 1; i++) {
    cin >> inorder[i];
    v_index[inorder[i]] = i;
  }

  for (int i = 1; i < n + 1; i++) {
    cin >> postorder[i];
  }

  printPreOrder(1, n, 1, n);

  return 0;
}

void printPreOrder(int is, int ie, int ps, int pe) {
  if (is > ie || ps > pe) return;

  int root = v_index[postorder[pe]];
  int left = root - is;
  int right = ie - root;

  cout << inorder[root] << " ";

  printPreOrder(is, root - 1, ps, ps + left - 1);
  printPreOrder(root + 1, ie, ps + left, pe - 1);
}