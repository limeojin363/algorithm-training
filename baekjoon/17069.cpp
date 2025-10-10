#include <iostream>
#include <cstring>

using namespace std;

long long dp(int state, int x, int y);
bool out(int x, int y);

int n;
int field[32][32];
long long cache[3][32][32]; // 첫번째 인수 - 0 : 가로, 1 : 세로, 2: 대각선

bool out(int x, int y)
{
    return (x < 0 || y < 0 || x >= n || y >= n);
}

// x, y에 걸치고 state 상태로 있을 때 목적지에 도달할 방법
long long dp(int state, int x, int y)
{
    long long &ret = cache[state][x][y];
    if (ret != -1)
        return ret;

    switch (state)
    {
    case 0:
        if (out(x, y + 1) || (field[x][y + 1] == 1))
            return 0;

        if ((x == n - 1) && (y + 1 == n - 1))
            return 1;
        break;

    case 1:
        if (out(x + 1, y) || (field[x + 1][y] == 1))
            return 0;

        if ((x + 1 == n - 1) && (y == n - 1))
            return 1;
        break;

    case 2:
        if (out(x + 1, y + 1) || (field[x + 1][y + 1] == 1) || (field[x + 1][y] == 1) || (field[x][y + 1] == 1))
            return 0;

        if ((x + 1 == n - 1) && (y + 1 == n - 1))
            return 1;
        break;
    }

    ret = 0;

    switch (state)
    {
    case 0:
        ret += dp(0, x, y + 1);
        ret += dp(2, x, y + 1);
        break;
    case 1:
        ret += dp(1, x + 1, y);
        ret += dp(2, x + 1, y);
        break;
    case 2:
        ret += dp(0, x + 1, y + 1);
        ret += dp(1, x + 1, y + 1);
        ret += dp(2, x + 1, y + 1);
        break;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> field[i][j];

    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, 0) << "\n";

    // for (int k = 0; k < 3; k++)
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //             cout << cache[k][i][j] << " ";
    //         cout << "\n";
    //     }
}