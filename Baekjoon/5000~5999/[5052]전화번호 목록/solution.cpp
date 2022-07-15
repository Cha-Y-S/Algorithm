#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

struct Node {
  bool is_end;
  Node *child[10];
  Node() {
    is_end = false;
    for (int i = 0; i < 10; i++) child[i] = NULL;
  }

  void insert(string s);
  bool check(string s);
};

vector<string> input;
int t, n;

void insert(string s);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;

  for (; t > 0; t--) {
    cin >> n;

    input = vector<string>(n);
    Node *trie = new Node();

    for (int i = 0; i < n; i++) {
      cin >> input[i];

      trie->insert(input[i]);
    }

    for (int i = 0; i < n; i++) {
      if (!trie->check(input[i])) {
        cout << "NO" << endl;
        break;
      }
      if (i + 1 >= n) {
        cout << "YES" << endl;
      }
    }
  }

  return 0;
}

void Node::insert(string s) {
  if (s.empty()) {
    is_end = true;
    return;
  }

  int num = s[0] - '0';
  s.erase(s.begin());

  if (child[num] == NULL) child[num] = new Node();
  child[num]->insert(s);
}

bool Node::check(string s) {
  if (s.empty()) return true;
  if (is_end) return false;

  int num = s[0] - '0';
  s.erase(s.begin());

  return child[num]->check(s);
}