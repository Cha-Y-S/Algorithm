#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

queue<int> q;
vector<int> josephus;
int N, K;

void print_josephus();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;

  for (int i = 0; i < N; i++)
    q.push(i + 1);

  int cnt = 0;

  while (!q.empty()) {
    if (cnt + 1 == K) {
      josephus.push_back(q.front());
      q.pop();
      cnt = 0;
      continue;
    }
    q.push(q.front());
    q.pop();
    cnt++;
  }

  print_josephus();

  return 0;
}

void print_josephus() {
  cout << "<";
  for (int i = 0; i < josephus.size(); i++) {
    cout << josephus[i];
    if (i + 1 != josephus.size()) cout << ", ";
  }
  cout << ">";
}