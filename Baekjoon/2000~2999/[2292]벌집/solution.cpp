#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> end_point;

  int n, i;

  cin >> n;

  end_point.push_back(1);
  i = 1;

  // Get each floor's end room number
  while (end_point[end_point.size() - 1] < n) {
    int sum = i++ * 6;
    end_point.push_back(sum + end_point[end_point.size() - 1]);
  }

  cout << end_point.size() << endl;

  return 0;
}