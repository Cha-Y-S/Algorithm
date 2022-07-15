#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num);

int main() {
  int size;

  cin >> size;

  vector<int> num(size, 0);

  for (int i = 0; i < size; i++) {
    cin >> num[i];
  }

  num = solution(num);

  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << endl;
  }

  return 0;
}

vector<int> solution(vector<int> num) {
  sort(num.begin(), num.end());
  return num;
}