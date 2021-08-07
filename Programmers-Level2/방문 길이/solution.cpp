#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(string dirs) {
  int answer = 0;
  map<char, pair<int, int>> dir;
  set<pair<pair<int, int>, pair<int, int>>> visited;
  pair<int, int> loc(0, 0);

  // Initialize direction for coordinate
  dir['U'] = make_pair(0, 1);
  dir['D'] = make_pair(0, -1);
  dir['R'] = make_pair(1, 0);
  dir['L'] = make_pair(-1, 0);

  for (int i = 0; i < dirs.size(); i++) {
    int cx = loc.first;
    int cy = loc.second;

    int nx = cx + dir[dirs[i]].first;
    int ny = cy + dir[dirs[i]].second;

    // If new location is outside on coordinate, do nothing
    if (!((-5 <= nx && nx <= 5) && (-5 <= ny && ny <= 5))) continue;

    pair<int, int> cur_loc(cx, cy);
    pair<int, int> new_loc(nx, ny);

    // Get the path from current location to new location
    pair<pair<int, int>, pair<int, int>> road;

    // Insert the path into visited set
    // If the path is already in the set, duplicate path will be removed
    visited.insert(road = {cur_loc, new_loc});
    visited.insert(road = {new_loc, cur_loc});

    // Update current location
    loc = new_loc;
  }

  // Visited set has two path about current and new location, so the answer is divide size of set by 2
  answer = visited.size() / 2;

  return answer;
}