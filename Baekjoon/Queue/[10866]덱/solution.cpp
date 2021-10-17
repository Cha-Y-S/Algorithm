#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

string method;
deque<int> dq;
map<string, int> query;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  query = {{"push_front", 1}, {"push_back", 2}, {"pop_front", 3}, {"pop_back", 4}, {"size", 5}, {"empty", 6}, {"front", 7}, {"back", 8}};

  for (int i = 0; i < N; i++) {
    cin >> method;

    if (query[method] <= 2) {
      int n;
      cin >> n;
      if (query[method] == 1)
        dq.push_front(n);
      else
        dq.push_back(n);
    } else {
      switch (query[method]) {
        case 5:
          cout << dq.size() << endl;
          break;
        case 6:
          cout << dq.empty() << endl;
          break;
        case 3:
        case 7:
          if (dq.empty())
            cout << -1 << endl;
          else {
            cout << dq.front() << endl;
            if (query[method] == 3) dq.pop_front();
          }
          break;
        case 4:
        case 8:
          if (dq.empty())
            cout << -1 << endl;
          else {
            cout << dq.back() << endl;
            if (query[method] == 4) dq.pop_back();
          }
          break;
      }
    }
  }
}