#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

map<string, pii> dirs;
pii king;
pii stone;
string init_king, init_stone, dir;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  dirs = {{"R", {1, 0}},
          {"L", {-1, 0}},
          {"B", {0, -1}},
          {"T", {0, 1}},
          {"RT", {1, 1}},
          {"LT", {-1, 1}},
          {"RB", {1, -1}},
          {"LB", {-1, -1}}};

  cin >> init_king >> init_stone >> N;

  king = {init_king[0] - 'A', init_king[1] - '1'};
  stone = {init_stone[0] - 'A', init_stone[1] - '1'};

  for (int i = 0; i < N; i++) {
    pii t_king, t_stone;

    cin >> dir;

    t_king = {dirs[dir].first + king.first, dirs[dir].second + king.second};

    if (t_king.first < 0 || t_king.second < 0 || t_king.first >= 8 || t_king.second >= 8) continue;

    if (t_king.first == stone.first && t_king.second == stone.second)
      t_stone = {dirs[dir].first + stone.first, dirs[dir].second + stone.second};
    else
      t_stone = stone;

    if (t_stone.first < 0 || t_stone.second < 0 || t_stone.first >= 8 || t_stone.second >= 8) continue;

    king = t_king;
    stone = t_stone;
  }

  cout << (char)(king.first + 'A') << king.second + 1 << endl;
  cout << (char)(stone.first + 'A') << stone.second + 1 << endl;

  return 0;
}
