#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> res;
int N, answer;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  res = vector<int>(N + 1);
  answer = 0;

  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    int t = i;
    while (true) {
      if (t % 5 == 0) {
        cnt++;
        t /= 5;
      } else
        break;
    }
    res[i] = cnt;
  }

  for (int i = 1; i <= N; i++)
    answer += res[i];

  cout << answer << endl;

  return 0;
}