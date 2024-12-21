#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[1003];
int value[1003][1003];
long long cache[1003];

long long dp(int idx)
{
    long long &ret = cache[idx];
    if (ret != -1)
        return ret;

    if (idx == n - 1)
        return ret = 0;

    ret = 0;

    for (int i = idx + 1; i <= n; i++)
        ret = max(dp(i) + value[idx][i - 1], ret);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < n; i++)
    {
        int maxNum = arr[i];
        int minNum = arr[i];

        value[i][i] = maxNum - minNum;

        for (int j = i; j < n; j++)
        {
            maxNum = max(maxNum, arr[j]);
            minNum = min(minNum, arr[j]);
            value[i][j] = maxNum - minNum;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //         cout << value[i][j] << " ";
    //     cout << "\n";
    // }

    cout << dp(0);

    // for (int i = 0; i < n; i++)
    //     cout << cache[i] << " ";
}