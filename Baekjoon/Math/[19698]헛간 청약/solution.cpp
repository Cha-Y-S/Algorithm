#include <iostream>

using namespace std;

#define endl "\n"

int N, W, H, L;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> W >> H >> L;

  cout << (((W / L) * (H / L)) > N ? N : (W / L) * (H / L)) << endl;

  return 0;
}