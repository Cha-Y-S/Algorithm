#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MOD 1000000007

int tmp1, tmp2, res;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    tmp1 = tmp2 = 1;

    for (int i = 3; i <= N; i++)
    {
        res = (tmp1 + tmp2) % MOD;
        tmp1 = tmp2;
        tmp2 = res;
    }

    cout << res << " " << N - 2 << endl;

    return 0;
}