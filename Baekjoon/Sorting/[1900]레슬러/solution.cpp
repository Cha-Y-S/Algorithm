#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

struct Player {
  int id;
  int power;
  int ring;
};

vector<Player> players;
int N;

int cmp(Player a, Player b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  players = vector<Player>(N);

  for (int i = 0; i < N; i++) {
    int p, r;

    cin >> p >> r;

    players[i].id = i + 1;
    players[i].power = p;
    players[i].ring = r;
  }

  sort(players.begin(), players.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << players[i].id << endl;
  }

  return 0;
}

int cmp(Player a, Player b) {
  return a.power + b.power * a.ring > b.power + a.power * b.ring;
}