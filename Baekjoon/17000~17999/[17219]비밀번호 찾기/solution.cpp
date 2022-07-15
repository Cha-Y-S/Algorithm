#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

map<string, string> pwd;
string site, password;
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> site >> password;

    pwd[site] = password;
  }

  for (int i = 0; i < M; i++) {
    cin >> site;

    cout << pwd[site] << endl;
  }

  return 0;
}