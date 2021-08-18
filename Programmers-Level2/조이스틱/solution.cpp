#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define min(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
  // If a and b have same distance, sort based on index
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int solution(string name) {
  int answer = 0;
  vector<pair<int, int>> not_a;
  int loc = 0;

  // Initialize vector with not 'A' character with character's index and distance from current location
  for (int i = 0; i < name.size(); i++) {
    if (name[i] != 'A') {
      int diff = i - loc;
      not_a.push_back({i, min(diff, name.size() - diff)});
    }
  }

  // Sorting vector based on distance
  sort(not_a.begin(), not_a.end(), compare);

  while (!not_a.empty()) {
    // Add amount of left or right movement
    loc = not_a[0].first;
    answer += not_a[0].second;
    char target = name[loc];

    not_a.erase(not_a.begin());

    // Add amount of up or down movement
    answer += target - 'A' < ('Z' - 'A') / 2 + 1 ? target - 'A' : 26 - (target - 'A');

    // Update not_a vector's distance value based on current location
    for (int i = 0; i < not_a.size(); i++) {
      int diff = not_a[i].first > loc ? not_a[i].first - loc : loc - not_a[i].first;
      not_a[i].second = min(diff, name.size() - diff);
    }

    sort(not_a.begin(), not_a.end(), compare);
  }

  return answer;
}