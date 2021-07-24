#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool isInside(int x, int y);
bool isVisited(set<pair<int, int>> visited, int x, int y);

int solution(string dirs) {
  int answer = 0;
  set<pair<int, int>> visited;
  pair<int, int> loc(0, 0);
  vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};

  for (int i = 0; i < dirs.size(); i++) {
    int cx = loc.first;
    int cy = loc.second;

    int nx, ny;
    switch (dirs[i]) {
      case 'U':
        nx = cx + dir[0].first;
        ny = cy + dir[0].second;
        break;
      case 'D':
        nx = cx + dir[1].first;
        ny = cy + dir[1].second;
        break;
      case 'R':
        nx = cx + dir[2].first;
        ny = cy + dir[2].second;
        break;
      case 'L':
        nx = cx + dir[3].first;
        ny = cy + dir[3].second;
        break;
    }

    if (isInside(nx, ny) && !isVisited(visited, nx, ny)) {
      loc.first = nx;
      loc.second = ny;

      set.insert(make_pair(loc.first, loc.second));
      answer++;
    }
  }

  return answer;
}

bool isInside(int x, int y) {
  return (-5 <= x && x <= 5) && (-5 <= y && y <= 5) ? true : false;
}

bool isVisited(set<pair<int, int>> visited, int x, int y) {
  set<pair<int, int>>::iterator it = visited.find(make_pair(x, y));

  return it == visited.end() ? false : true;
}