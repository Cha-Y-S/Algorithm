#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<string, string> pss;

vector<pss> words;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> N;

    if (N == 0)
      break;

    words = vector<pss>(N);

    for (int i = 0; i < N; i++) {
      string input;

      cin >> input;

      words[i].second = input;

      transform(input.begin(), input.end(), input.begin(), ::toupper);

      words[i].first = input;
    }

    sort(words.begin(), words.end());

    cout << words[0].second << endl;
  }

  return 0;
}