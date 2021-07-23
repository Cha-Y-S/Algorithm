#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> coin, int money);

int main() {
  int n, k;

  cin >> n >> k;

  vector<int> coin(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> coin[i];
  }

  cout << solution(coin, k) << endl;

  return 0;
}

int solution(vector<int> coin, int money) {
  int answer = 0;

  for (int i = coin.size(); i > 0; i--) {
    if (money >= coin[i - 1]) {
      answer += money / coin[i - 1];
      money -= money / coin[i - 1] * coin[i - 1];
    }
  }

  return answer;
}