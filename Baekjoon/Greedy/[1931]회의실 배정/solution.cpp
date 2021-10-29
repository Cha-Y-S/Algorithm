#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> conference;
vector<bool> used;
int N, res, finish;

bool comp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  conference = vector<pii>(N);
  res = 1;

  for (int i = 0; i < N; i++)
    cin >> conference[i].first >> conference[i].second;

  sort(conference.begin(), conference.end(), comp);

  finish = conference[0].second;

  for (int i = 1; i < N; i++) {
    if (conference[i].first >= finish) {
      res++;
      finish = conference[i].second;
    }
  }

  cout << res << endl;

  return 0;
}

bool comp(pii a, pii b) {
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}