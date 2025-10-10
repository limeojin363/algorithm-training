#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 123456789

using namespace std;

int dp(int x, int y, int xx, int yy);

int n, m;
int arr[51][51];
int cache[51][51][51][51];
int visited[51][51][51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int out(int x, int y)
{
    return (x < 0 || y < 0 || x >= n || y >= m);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            arr[i][j] = (str[j] == 'H' ? 0 : str[j] - 48);
    }

    memset(cache, -1, sizeof(cache));
    memset(visited, 0, sizeof(visited));

    int res = dp(0, 0, 0, 0);
    if (res == INF)
        cout << -1;
    else
        cout << res;
}

int dp(int x, int y, int xx, int yy)
{
    int &ret = cache[x][y][xx][yy];
    if (visited[x][y][xx][yy] == 1)
        return ret = INF;
    if (ret != -1)
        return ret;

    visited[x][y][xx][yy] = 1;

    ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i] * arr[x][y];
        int ny = y + dy[i] * arr[x][y];

        if (out(nx, ny) || (arr[nx][ny] == 0))
            continue;

        int val = dp(nx, ny, x, y);
        if (val == INF)
        {
            ret = INF;
            break;
        }
        ret = max(ret, 1 + dp(nx, ny, x, y));
    }

    visited[x][y][xx][yy] = 0;

    return ret;
}