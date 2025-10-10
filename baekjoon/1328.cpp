#include <iostream>
#include <cstring>

using namespace std;

int n, l, r;
long long cache[101][101][101];

// 높이가 가장 큰 빌딩부터 놓기 시작
// 첫번째부터 idx번째까지(n ~ n - idx + 1) 빌딩을 놓았을 때, l, r값이 now_l, now_r인 경우의 수를 구함
long long dp(int idx, int now_l, int now_r);

int main()
{
    cin >> n >> l >> r;

    memset(cache, -1, sizeof(cache));

    cout << dp(n, l, r);
}

long long dp(int idx, int now_l, int now_r)
{
    if (idx == 1)
    {
        if ((now_l == 1) && (now_r == 1))
            return 1;
        return 0;
    }

    long long &ret = cache[idx][now_l][now_r];
    if (ret != -1)
        return ret;

    return ret = (dp(idx - 1, now_l - 1, now_r) + dp(idx - 1, now_l, now_r - 1) + dp(idx - 1, now_l, now_r) * (idx - 2)) % 1000000007;
}