#include <iostream>
#include <vector>

using namespace std;

int solution(int x, int y);

int main() {
  int x, y;

  cin >> x >> y;

  cout << solution(x, y) << endl;

  return 0;
}

int solution(int x, int y) {
  int answer = 0;
  vector<pair<int, int>> quad = {make_pair(1, 1), make_pair(-1, 1), make_pair(-1, -1), make_pair(1, -1)};

  for (int i = 0; i < quad.size(); i++) {
    if (x * quad[i].first > 0 && y * quad[i].second > 0)
      answer = i + 1;
  }

  return answer;
}