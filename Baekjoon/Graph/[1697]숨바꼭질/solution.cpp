#include <iostream>
#include <queue>
#include <vector>

#define MAX 100000

using namespace std;

int solution(int n, int k);

int main() {
  int n, k;

  cin >> n >> k;

  cout << solution(n, k) << endl;

  return 0;
}

int solution(int n, int k) {
  int answer = 0;
  vector<bool> visited(MAX + 1, false);
  queue<pair<int, int>> q;

  q.push(make_pair(n, 0));
  visited[n] = true;

  if (n == k) {
    return answer;
  }

  while (!q.empty()) {
    int location = q.front().first;
    int time = q.front().second;

    q.pop();

    if (location == k) {
      answer = time;
      break;
    }

    if (location - 1 >= 0 && !visited[location - 1]) {
      visited[location - 1] = true;
      q.push(make_pair(location - 1, time + 1));
    }
    if (location + 1 <= 100000 && !visited[location + 1]) {
      visited[location + 1] = true;
      q.push(make_pair(location + 1, time + 1));
    }
    if (location * 2 <= 100000 && !visited[location * 2]) {
      visited[location * 2] = true;
      q.push(make_pair(location * 2, time + 1));
    }
  }

  return answer;
}