#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef long long ll;

vector<ll> seg_tree;
vector<int> array;
int N, Q, X, Y, A, B;
ll res;

void fast_io();
void configure_segment_tree();
void set_tree_size();
ll init_segment_tree(int node, int start, int end);
void swap(int &a, int &b);
ll get_prefix_sum(int node, int start, int end, int left, int right);
void update_segment_tree(int node, int start, int end, int index, ll diff);

int main() {
  fast_io();

  cin >> N >> Q;

  array = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  configure_segment_tree();

  for (int i = 0; i < Q; i++) {
    cin >> X >> Y >> A >> B;

    X--;
    Y--;
    A--;

    swap(X, Y);

    cout << get_prefix_sum(1, 0, N - 1, X, Y) << endl;

    // Get difference between current value and value that will be changed
    ll diff = B - (array[A] * 1L);
    array[A] = B;

    update_segment_tree(1, 0, N - 1, A, diff);
  }

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void configure_segment_tree() {
  set_tree_size();
  init_segment_tree(1, 0, N - 1);
}

// Get Tree size and Set Tree size
void set_tree_size() {
  int tree_height = (int)ceil(log2(N));
  int tree_size = (1 << (tree_height + 1));
  seg_tree = vector<ll>(tree_size);
}

// Create Segment Tree
ll init_segment_tree(int node, int start, int end) {
  if (start == end) return seg_tree[node] = array[start];

  int mid = (start + end) / 2;
  ll left_result = init_segment_tree(node * 2, start, mid);
  ll right_result = init_segment_tree(node * 2 + 1, mid + 1, end);

  return seg_tree[node] = left_result + right_result;
}

void swap(int &a, int &b) {
  if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
}

// Get Prefix Sum on the segment tree
ll get_prefix_sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && end <= right) return seg_tree[node];

  int mid = (start + end) / 2;
  ll left_result = get_prefix_sum(node * 2, start, mid, left, right);
  ll right_result = get_prefix_sum(node * 2 + 1, mid + 1, end, left, right);

  return left_result + right_result;
}

// Update Segment Tree according to given command
void update_segment_tree(int node, int start, int end, int index, ll diff) {
  if (index < start || index > end) return;

  seg_tree[node] = seg_tree[node] + diff;

  if (start != end) {
    int mid = (start + end) / 2;
    update_segment_tree(node * 2, start, mid, index, diff);
    update_segment_tree(node * 2 + 1, mid + 1, end, index, diff);
  }
}