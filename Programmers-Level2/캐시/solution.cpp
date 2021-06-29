#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;
  vector<string> cache;

  for (int i = 0; i < cities.size(); i++) {
    string upperCity = cities[i];
    transform(upperCity.begin(), upperCity.end(), upperCity.begin(), ::toupper);
    bool inCache = false;

    for (string city : cache) {
      if (city == upperCity) {
        answer++;
        inCache = true;
        break;
      }
    }

    if (!inCache)
      answer += 5;

    cache.push_back(upperCity);

    if (inCache || cache.size() > cacheSize) {
      int toErase = 0;
      for (int i = 0; i < cache.size() - 1; i++) {
        if (cache[i] == upperCity) {
          toErase = i;
          break;
        }
      }
      cache.erase(cache.begin() + toErase, cache.begin() + toErase + 1);
    }
  }

  return answer;
}