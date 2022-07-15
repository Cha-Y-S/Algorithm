#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  vector<int> cards;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int card;

    cin >> card;

    cards.push_back(card);
  }

  int max = INT_MIN;
  for (int i = 0; i < cards.size() - 2; i++) {
    int card1 = cards[i];
    for (int j = i + 1; j < cards.size() - 1; j++) {
      int card2 = cards[j];
      for (int k = j + 1; k < cards.size(); k++) {
        int card3 = cards[k];

        max = max < card1 + card2 + card3 && card1 + card2 + card3 <= m ? card1 + card2 + card3 : max;
      }
    }
  }

  cout << max << endl;

  return 0;
}