#include <iostream>
#include <cstring>

using namespace std;

bool out(int x, int y);
int dp(int prev, int x, int y);

int n, m;
int land[1001][1001];
int cache[3][1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> land[i][j];

    memset(cache, -1, sizeof(cache));

    cout << land[0][0] + dp(0, 0, 0);
}

bool out(int x, int y)
{
    return x < 0 || y < 0 || x >= n || y >= m;
}

// prev - 이전에 ( 0: 아래, 1: 오른쪽, 2: 왼쪽 )으로 이동..
int dp(int prev, int x, int y)
{
    int &ret = cache[prev][x][y];

    if (ret != -1)
        return ret;

    // 마지막 가로줄에 도달
    if (x == n - 1)
    {
        ret = 0;
        for (int i = y + 1; i < m; i++)
            ret += land[x][i];

        return ret;
    }

    ret = dp(0, x + 1, y) + land[x + 1][y];

    // 전에 왼쪽으로 이동하지 않았음 -> 오른쪽 가능
    if (prev != 2 && !out(x, y + 1))
    {
        int cand = dp(1, x, y + 1) + land[x][y + 1];
        ret = max(ret, cand);
    }

    // 전에 오른으로 이동하지 않았음 -> 왼쪽 가능
    if (prev != 1 && !out(x, y - 1))
    {
        int cand = dp(2, x, y - 1) + land[x][y - 1];
        ret = max(ret, cand);
    }

    return ret;
}