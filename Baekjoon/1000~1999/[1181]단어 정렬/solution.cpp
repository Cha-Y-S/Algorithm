#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(string a, string b);
vector<string> solution(vector<string> arr);

int main() {
  int n;

  cin >> n;

  vector<string> arr(n, "");

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  arr = solution(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
  }

  return 0;
}

int compare(string a, string b) {
  return a.size() != b.size() ? a.size() < b.size() : a < b;
}

vector<string> solution(vector<string> arr) {
  vector<string> answer;

  sort(arr.begin(), arr.end(), compare);

  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  answer = arr;

  return answer;
}