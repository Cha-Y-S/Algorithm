#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> seq);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;

  cin >> n;

  vector<int> seq(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }

  // vector<int> seq = {10, 20, 10, 30, 20, 50};

  cout << solution(seq) << endl;

  return 0;
}

int solution(vector<int> seq) {
  int answer = 0;
  vector<int> dp(seq.size(), 0);

  return answer;
}