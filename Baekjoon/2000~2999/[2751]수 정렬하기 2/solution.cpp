#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int size;

  cin >> size;

  vector<int> num(size, 0);

  for (int i = 0; i < size; i++) {
    scanf("%d", &num[i]);
  }

  sort(num.begin(), num.end());

  for (int i = 0; i < num.size(); i++) {
    printf("%d\n", num[i]);
  }

  return 0;
}