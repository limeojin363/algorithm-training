#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

char arr[1001][1001];
int r, c;
int f_visited[1001][1001];
int j_visited[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

pair<int, int> j_start;
vector<pair<int, int>> f_start_list;

int main()
{
    cin >> r >> c;

    memset(f_visited, -1, sizeof(f_visited));
    memset(j_visited, -1, sizeof(j_visited));

    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < c; j++)
        {
            arr[i][j] = str[j];
            if (arr[i][j] == 'J')
                j_start = {i, j};
            else if (arr[i][j] == 'F')
                f_start_list.push_back({i, j});
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < f_start_list.size(); i++)
    {
        q.push(f_start_list[i]);
        f_visited[f_start_list[i].first][f_start_list[i].second] = 0;
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c)
                continue;
            if (f_visited[nx][ny] != -1)
                continue;
            if (arr[nx][ny] == '#')
                continue;

            q.push({nx, ny});
            f_visited[nx][ny] = f_visited[x][y] + 1;
        }
    }

    q.push(j_start);
    j_visited[j_start.first][j_start.second] = 0;

    int ans = 123456789;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            {
                ans = min(ans, j_visited[x][y] + 1);
                continue;
            }
            if (j_visited[nx][ny] != -1)
            {
                continue;
            }
            if (f_visited[nx][ny] != -1 && (j_visited[x][y] + 1 >= f_visited[nx][ny]))
            {
                continue;
            }
            if (arr[nx][ny] == '#')
            {
                continue;
            }

            q.push({nx, ny});
            j_visited[nx][ny] = j_visited[x][y] + 1;
        }
    }


    if (ans == 123456789)
        cout << "IMPOSSIBLE";
    else
        cout << ans;
}