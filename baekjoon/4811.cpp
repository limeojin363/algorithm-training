#include <iostream>
#include <cstring>

using namespace std;

int t, n;
long long cache[63][32];

long long dp(int remaining_intact, int remaining_half)
{
    if (remaining_half == -1 || remaining_intact == -1)
        return 0;
    if (remaining_intact == 0 && remaining_half == 0)
        return 1;

    long long &ret = cache[remaining_intact][remaining_half];
    if (ret != -1)
        return ret;

    return (ret = dp(remaining_intact - 1, remaining_half + 1) + dp(remaining_intact, remaining_half - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << dp(n, 0) << "\n";
    }
}