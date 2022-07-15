#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> location;
int N;
int answer = 0;

bool possible(int r);
void locate(int r);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  location = vector<int>(N);

  locate(0);

  cout << answer << endl;

  return 0;
}

bool possible(int r) {
  for (int i = 0; i < r; i++) {
    if ((location[i] == location[r]) || (r - i == (abs(location[r] - location[i]))))
      return false;
  }
  return true;
}

void locate(int r) {
  if (r == N) {
    answer++;
    return;
  }
  for (int i = 0; i < N; i++) {
    location[r] = i;

    if (possible(r))
      locate(r + 1);
  }
}