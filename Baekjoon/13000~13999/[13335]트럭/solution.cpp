#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<int> trucks;
queue<pii> bridge;
int N, W, L, idx, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> W >> L;

  trucks = vector<int>(N);
  idx = res = 0;

  for (int i = 0; i < N; i++) {
    cin >> trucks[i];
  }

  do {
    vector<pii> current;
    int cur_weight = 0;
    int cur_truck;

    // check about the bridge
    while (!bridge.empty()) {
      int truck_weight = bridge.front().first;
      int truck_time = bridge.front().second;

      bridge.pop();

      // check whether the truck crossed the bridge
      if (truck_time < W) {
        current.push_back({truck_weight, truck_time});
      }
    }

    // check # of truck on the bridge
    cur_truck = current.size();

    // check sum of truck's weight on the bridge
    for (int i = 0; i < current.size(); i++) {
      bridge.push({current[i].first, current[i].second + 1});

      cur_weight += current[i].first;
    }

    if (idx < N && cur_weight + trucks[idx] <= L && cur_truck < W) {
      bridge.push({trucks[idx++], 1});
    }
    res++;
  } while (!bridge.empty());

  cout << res << endl;

  return 0;
}