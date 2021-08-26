#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 1010000

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<bool> eratos(MAX, true);

  eratos[0] = eratos[1] = false;
  for (int i = 2; i < MAX; i++) {
    if (!eratos[i]) continue;
    for (int j = i + i; j < MAX; j += i) {
      eratos[j] = false;
    }
  }

  int n;

  cin >> n;

  for (int i = n; i < MAX; i++) {
    bool isFind = false;
    if (eratos[i]) {
      string temp = to_string(i);

      if (temp.size() == 1) {
        cout << i << endl;
        break;
      }

      for (int j = 0; j < temp.size() / 2; j++) {
        if (temp[j] == temp[temp.size() - j - 1]) {
          if (j + 1 == temp.size() / 2) {
            cout << i << endl;
            isFind = true;
            break;
          }
        } else {
          break;
        }
      }
    }
    if (isFind) break;
  }

  return 0;
}