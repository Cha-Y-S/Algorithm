#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

#define endl "\n"

queue<int> q;
string method;
map<string, int> query;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  query = {{"push", 1}, {"pop", 2}, {"size", 3}, {"empty", 4}, {"front", 5}, {"back", 6}};

  for (int i = 0; i < N; i++) {
    cin >> method;

    switch (query[method]) {
      case 1:
        int n;
        cin >> n;
        q.push(n);
        break;
      case 2:
        if (q.empty())
          cout << -1 << endl;
        else {
          cout << q.front() << endl;
          q.pop();
        }
        break;
      case 3:
        cout << q.size() << endl;
        break;
      case 4:
        cout << q.empty() << endl;
        break;
      case 5:
        if (q.empty())
          cout << -1 << endl;
        else
          cout << q.front() << endl;
        break;
      case 6:
        if (q.empty())
          cout << -1 << endl;
        else
          cout << q.back() << endl;
        break;
    }
  }

  return 0;
}