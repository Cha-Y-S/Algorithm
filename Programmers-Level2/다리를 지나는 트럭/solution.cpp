#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  vector<pair<int, int>> bridge;
  int curWeight = 0;
  int truck = truck_weights.size();
  int gone = 0;

  while (gone < truck) {
    for (int i = 0; i < bridge.size(); i++) {
      // Relocate truck's location and Remove truck that crossed the bridge
      if (++bridge[i].second > bridge_length) {
        curWeight -= bridge[i].first;
        bridge.erase(bridge.begin() + i, bridge.begin() + i + 1);
        gone++;
        i--;
      }
      // Bridge's role is same with queue
      // Because bridge[i].second(truck's location) is added only by 1 at a time
      // and truck is pushed into the bridge only by 1 at a time
    }

    // If truck could be on the bridge, push into bridge that truck and add weight into curWeight
    if (curWeight + truck_weights[0] <= weight && !truck_weights.empty()) {
      bridge.push_back(make_pair(truck_weights[0], 1));
      curWeight += truck_weights[0];
      truck_weights.erase(truck_weights.begin(), truck_weights.begin() + 1);
    }

    // Count time
    answer++;
  }

  return answer;
}