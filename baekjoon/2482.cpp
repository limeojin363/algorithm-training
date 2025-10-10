#include <iostream>
#include <cstring>

using namespace std;

// idx부터 선택가능할 때 가능한 경우의 수
int dp(int firstSelected, int idx, int remaining);

int n, k;
int cache[2][1001][1001];

int main()
{
    cin >> n >> k;

    memset(cache, -1, sizeof(cache));

    cout << (dp(0, 1, k) + dp(1, 2, k - 1)) % 1000000003;
}

int dp(int firstSelected, int idx, int remaining)
{
    if (!!remaining && firstSelected && (idx >= n - 1))
        return 0;
    if (!!remaining && !firstSelected && (idx >= n))
        return 0;

    int &ret = cache[firstSelected][idx][remaining];
    if (ret != -1)
        return ret;

    if (remaining == 0)
        return ret = 1;

    ret = 0;
    // idx 선택
    ret += dp(firstSelected, idx + 2, remaining - 1);
    // idx 미선택
    ret += dp(firstSelected, idx + 1, remaining);

    ret %= 1000000003;

    return ret;
}