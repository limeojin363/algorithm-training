#include <iostream>
#include <cstring>

using namespace std;

int t, w;
int tree[1001];
int cache[31][1001][2];

int dp(int moved, int time, int nowTree);

int main()
{
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> tree[i];

    memset(cache, -1, sizeof(cache));

    cout << dp(0, 0, 1);
}

int dp(int moved, int time, int nowTree)
{
    int &ret = cache[moved][time][nowTree];
    if (ret != -1)
        return ret;

    if (time == t + 1)
        return 0;

    int ifStay = (nowTree == tree[time] ? 1 : 0) + dp(moved, time + 1, nowTree);

    if (moved == w)
        return ret = ifStay;

    int ifMove = (nowTree == tree[time] ? 1 : 0) + dp(moved + 1, time + 1, (nowTree == 1 ? 2 : 1));

    return ret = max(ifMove, ifStay);
}