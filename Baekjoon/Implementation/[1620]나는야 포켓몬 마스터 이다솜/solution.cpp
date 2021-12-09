#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

map<string, int> name_pocket;
map<int, string> num_pocket;
string pocketmon, target;
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> pocketmon;

    name_pocket[pocketmon] = i + 1;
    num_pocket[i + 1] = pocketmon;
  }

  for (int i = 0; i < M; i++) {
    cin >> target;

    if (isdigit(target[0]))
      cout << num_pocket[stoi(target)] << endl;
    else
      cout << name_pocket[target] << endl;
  }

  return 0;
}