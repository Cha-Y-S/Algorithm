#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<string> files;
string res;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  files = vector<string>(N);
  res = "";

  for (int i = 0; i < N; i++)
    cin >> files[i];

  for (int i = 0; i < files[0].size(); i++) {
    bool flag = true;
    for (int j = 0; j < files.size() - 1; j++) {
      if (files[j][i] != files[j + 1][i]) {
        flag = false;
        break;
      }
    }
    if (flag)
      res.push_back(files[0][i]);
    else
      res.push_back('?');
  }

  cout << res << endl;

  return 0;
}