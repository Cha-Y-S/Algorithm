#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<char, bool> pcb;

vector<pcb> alpha;
vector<char> pw;
set<char> vowels;
int L, C;

void make_password(int idx, int cnt);
void print_password();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> L >> C;

  alpha = vector<pcb>(C, {0, false});
  pw = vector<char>(L);
  vowels.insert({'a', 'e', 'i', 'o', 'u'});

  for (int i = 0; i < C; i++)
    cin >> alpha[i].first;

  sort(alpha.begin(), alpha.end());

  make_password(0, 0);

  return 0;
}

void make_password(int idx, int cnt) {
  if (cnt == L) {
    print_password();
    return;
  }

  for (int i = idx; i < C; i++) {
    if (alpha[i].second) continue;
    alpha[i].second = true;
    pw[cnt] = alpha[i].first;
    make_password(i + 1, cnt + 1);
    alpha[i].second = false;
  }
}

void print_password() {
  int vowel = 0;
  int consonant = 0;

  for (int i = 0; i < L; i++) {
    if (vowels.find(pw[i]) != vowels.end())
      vowel++;
    else
      consonant++;
  }

  if (vowel >= 1 && consonant >= 2) {
    for (int i = 0; i < L; i++)
      cout << pw[i];
    cout << endl;
  }
}