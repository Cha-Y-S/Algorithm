#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> br;
int N, M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  br = vector<int>(N);

  int left = 0;
  int right = 0;

  for (int i = 0; i < N; i++) {
    cin >> br[i];
    right += br[i];
    left = max(left, br[i]);
  }

  while (left <= right) {
    int cnt = 0;
    int temp = 0;
    int mid = (left + right) / 2;

    for (int i = 0; i < N; i++) {
      if (temp + br[i] > mid) {
        temp = 0;
        cnt++;
      }
      temp += br[i];
    }

    // mid보다 작아서 1 증가시키지 못했을 경우
    if (temp != 0) cnt += 1;

    if (cnt <= M) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << left << endl;

  return 0;
}