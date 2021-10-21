#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<pii> machine;
int K;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> K;

  machine = vector<pii>(K + 1, {1, 0});

  for (int i = 1; i <= K; i++) {
    machine[i].first = machine[i - 1].second;
    machine[i].second = machine[i - 1].first + machine[i - 1].second;
  }

  cout << machine[K].first << " " << machine[K].second << endl;

  return 0;
}