#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int n);

int solution(string numbers) {
  int answer = 0;
  vector<int> partials;
  for (int i = 0; i < numbers.size(); i++) {
    vector<bool> v(numbers.size() - (i + 1), false);
    v.insert(v.end(), i + 1, true);

    // Select numbers' element by i
    do {
      string num;
      for (int j = 0; j < v.size(); j++)
        if (v[j]) num.push_back(numbers[j]);

      // Place each number with no order
      sort(num.begin(), num.end());
      do {
        partials.push_back(stoi(num));
      } while (next_permutation(num.begin(), num.end()));

    } while (next_permutation(v.begin(), v.end()));
  }

  // Remove duplicate element of vector

  sort(partials.begin(), partials.end());

  partials.erase(unique(partials.begin(), partials.end()), partials.end());

  for (int i = 0; i < partials.size(); i++)
    if (isPrime(partials[i])) answer++;

  return answer;
}

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}