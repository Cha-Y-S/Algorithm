#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

string S;
int N, M, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> S;

  for (int i = 0; i < M; i++) {
    int cnt = 0;
    if (S[i] == 'I') {
      while (S[i + 1] == 'O' && S[i + 2] == 'I') {
        cnt++;
        if (cnt == N) {
          cnt--;
          res++;
        }
        i += 2;
      }
      cnt = 0;
    }
  }

  cout << res << endl;

  return 0;
}