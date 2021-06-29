#include "solution.h"

int main() {
  vector<string> cities;

  cout << solution(3, cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl;

  cout << solution(3, cities = {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"}) << endl;

  cout << solution(2, cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}) << endl;

  cout << solution(5, cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}) << endl;

  cout << solution(2, cities = {"Jeju", "Pangyo", "NewYork", "newyork"}) << endl;

  cout << solution(0, cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl;

  return 0;
}