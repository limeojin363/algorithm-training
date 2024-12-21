#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll dp(int idx, int nowNum);

int n;
int arr[110];
ll cache[110][21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << dp(1, arr[0]);
}

ll dp(int idx, int nowNum)
{
    if (nowNum < 0 || nowNum > 20)
        return 0;

    ll &ret = cache[idx][nowNum];
    if (ret != -1)
        return ret;

    if ((n - 2) == idx)
        return ret = ((nowNum + arr[idx] == arr[idx + 1]) + (nowNum - arr[idx] == arr[idx + 1]));

    return ret =
               dp(idx + 1, nowNum + arr[idx]) +
               dp(idx + 1, nowNum - arr[idx]);
}