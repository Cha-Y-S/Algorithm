#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> coin, int money);

int main() {
  vector<int> coin = {500, 100, 50, 10, 5, 1};
  int money;

  cin >> money;

  cout << solution(coin, 1000 - money) << endl;

  return 0;
}

int solution(vector<int> coin, int money) {
  int answer = 0;

  for (int i = 0; i < coin.size(); i++) {
    if (money >= coin[i]) {
      answer += money / coin[i];
      money -= money / coin[i] * coin[i];
    }
  }

  return answer;
}