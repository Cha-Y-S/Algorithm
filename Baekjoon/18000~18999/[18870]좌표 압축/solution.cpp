#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> seq;
vector<int> seq_copy;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  seq_copy = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
    seq_copy[i] = seq[i];
  }

  sort(seq_copy.begin(), seq_copy.end());
  seq_copy.erase(unique(seq_copy.begin(), seq_copy.end()), seq_copy.end());

  for (int i = 0; i < N; i++) {
    vector<int>::iterator it = lower_bound(seq_copy.begin(), seq_copy.end(), seq[i]);

    cout << it - seq_copy.begin() << " ";
  }
  cout << endl;

  return 0;
}