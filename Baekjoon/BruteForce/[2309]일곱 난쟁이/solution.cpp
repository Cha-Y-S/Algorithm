#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  vector<int> dwarfs(9, 0);
  vector<int> answer;

  for (int i = 0; i < dwarfs.size(); i++) {
    cin >> dwarfs[i];
  }

  sort(dwarfs.begin(), dwarfs.end());

  do {
    int sum = accumulate(dwarfs.begin(), dwarfs.begin() + 7, 0);

    if (sum == 100) {
      for (int i = 0; i < 7; i++) {
        answer.push_back(dwarfs[i]);
      }

      break;
    }
  } while (next_permutation(dwarfs.begin(), dwarfs.end()));

  sort(answer.begin(), answer.end());

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }

  return 0;
}