#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int size;

  cin >> size;

  vector<int> count(10000, 0);

  for (int i = 0; i < size; i++) {
    short input;
    scanf("%hd", &input);
    count[input - 1]++;
  }

  for (int i = 0; i < count.size(); i++) {
    for (int j = 0; j < count[i]; j++) {
      printf("%d\n", i + 1);
    }
  }

  return 0;
}