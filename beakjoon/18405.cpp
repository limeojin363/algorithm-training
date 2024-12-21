#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
pair<int, int> arr[201][201]; // 순서대로 바이러스 번호, 도달 시간

int n, k, s, x, y;

bool out(int x, int y)
{
    return (x < 0 || y < 0 || x >= n || y >= n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j].first;

    cin >> s >> x >> y;

    queue<pair<int, int>> q; // 순서대로 x, y
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j].first != 0)
            {
                arr[i][j].second = s;
                q.push(make_pair(i, j));
            }

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();

        if (arr[xx][yy].second == 0)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (out(nx, ny))
                continue;

            if (arr[nx][ny].first == 0 || ((arr[nx][ny].second == arr[xx][yy].second - 1) && (arr[nx][ny].first > arr[xx][yy].first)))
            {
                arr[nx][ny] = {arr[xx][yy].first, arr[xx][yy].second - 1};
                q.push({nx, ny});
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "\n";
    //     for (int j = 0; j < n; j++)
    //         cout << arr[i][j].first << " ";
    // }

    cout << arr[x - 1][y - 1].first;
}