#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> room;
int N;
bool flag;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  room = vector<int>(3);
  flag = false;

  for (int i = 0; i < 3; i++)
    cin >> room[i];

  cin >> N;

  for (int i = 0; i <= N; i++) {
    int a = room[0] * i;

    for (int j = 0; j <= N; j++) {
      int b = room[1] * j;

      for (int k = 0; k <= N; k++) {
        int c = room[2] * k;

        if (a + b + c == N) flag = true;
      }
      if (flag) break;
    }
    if (flag) break;
  }

  cout << (flag ? 1 : 0) << endl;

  return 0;
}