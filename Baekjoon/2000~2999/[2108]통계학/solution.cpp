#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> freq;
vector<int> seq;
map<int, int> m;
int N, median, mode, scope, max_num, min_num;
double avg;

bool comp(pii a, pii b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  seq = vector<int>(N);
  avg = 0;
  max_num = -4001;
  min_num = 4001;

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
    avg += seq[i];
    m[seq[i]]++;

    max_num = max_num < seq[i] ? seq[i] : max_num;
    min_num = min_num > seq[i] ? seq[i] : min_num;
  }

  for (pii e : m)
    freq.push_back(e);

  sort(seq.begin(), seq.end());
  sort(freq.begin(), freq.end(), comp);

  avg = round(avg / N);
  median = seq[N / 2];

  if (freq.size() >= 2) {
    if (freq[0].second > freq[1].second)
      mode = freq[0].first;
    else
      mode = freq[1].first;
  } else
    mode = freq[0].first;

  scope = max_num - min_num;

  cout << (int)avg << endl
       << median << endl
       << mode << endl
       << scope << endl;

  return 0;
}

bool comp(pii a, pii b) {
  return a.second != b.second ? a.second > b.second : a.first < b.first;
}