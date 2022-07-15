#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<char> yoot;
int cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  yoot = {'E', 'A', 'B', 'C', 'D'};

  for (int i = 0; i < 3; i++) {
    cnt = 0;
    for (int j = 0; j < 4; j++) {
      int num;

      cin >> num;

      cnt = num == 0 ? cnt + 1 : cnt;
    }

    cout << yoot[cnt] << endl;
  }

  return 0;
}