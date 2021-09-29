#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, bool> pib;

vector<pib> nums;
vector<int> lotto;
int k;

void combination(int idx, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> k;

    if (k == 0) break;

    nums = vector<pib>(k, {0, false});
    lotto = vector<int>(6);

    for (int i = 0; i < k; i++)
      cin >> nums[i].first;

    combination(0, 0);

    cout << endl;
  }

  return 0;
}

void combination(int idx, int cnt) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++)
      cout << lotto[i] << " ";
    cout << endl;
    return;
  }
  for (int i = idx; i < k; i++) {
    if (nums[i].second) continue;
    nums[i].second = true;
    lotto[cnt] = nums[i].first;
    combination(i + 1, cnt + 1);
    nums[i].second = false;
  }
}
