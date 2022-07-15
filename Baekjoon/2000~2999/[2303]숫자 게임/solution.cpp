#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> player;
vector<int> cards;
int N;

int cmp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  player = vector<pii>(N);

  for (int p = 0; p < N; p++) {
    cards = vector<int>(5);

    for (int i = 0; i < 5; i++) {
      cin >> cards[i];
    }

    int sum = 0;

    for (int i = 0; i < 5; i++) {
      int tmp = 0;
      for (int j = i + 1; j < 5; j++) {
        for (int k = j + 1; k < 5; k++) {
          tmp = (cards[i] + cards[j] + cards[k]) % 10;

          sum = tmp > sum ? tmp : sum;
        }
      }
    }
    player[p] = {sum, p + 1};
  }

  sort(player.begin(), player.end(), cmp);

  cout << player[0].second << endl;

  return 0;
}

int cmp(pii a, pii b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second > b.second;
  }
}