#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 1001

vector<int> v_index;
vector<int> preorder;
vector<int> inorder;
int t, n;

void getPostOrder(int ps, int pe, int is, int ie);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  preorder = vector<int>(MAX);
  inorder = vector<int>(MAX);
  v_index = vector<int>(MAX);

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> preorder[i];

    for (int i = 0; i < n; i++) {
      cin >> inorder[i];
      v_index[inorder[i]] = i;
    }

    getPostOrder(0, n - 1, 0, n - 1);

    cout << endl;

    preorder.clear();
    inorder.clear();
    v_index.clear();
  }

  return 0;
}

void getPostOrder(int ps, int pe, int is, int ie) {
  if (ps > pe || is > ie) return;

  int r_index = v_index[preorder[ps]];
  int left = r_index - is;
  int right = ie - r_index;

  getPostOrder(ps + 1, ps + left, is, is + left - 1);
  getPostOrder(ps + left + 1, ps + left + right, r_index + 1, ie);

  cout << inorder[r_index] << " ";
}