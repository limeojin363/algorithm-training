#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

void run();

char field[12][6];
bool changed;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    for (int i = 0; i < 12; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 6; j++)
            field[i][j] = str[j];
    }

    int res = 0;

    while (1)
    {
        run();
        if (!changed)
            break;

        // for (int i = 0; i < 12; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //         cout << field[i][j];
        //     cout << "\n";
        // }

        res++;
    }

    cout << res;
}

bool out(int x, int y)
{
    return x < 0 || y < 0 || x >= 12 || y >= 6;
}

void run()
{
    changed = false;

    int visited[12][6];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
        {
            if (field[i][j] != '.')
            {
                char nowColor = field[i][j];

                queue<pair<int, int>> q = {};  // bfs queue용
                vector<pair<int, int>> v = {}; // cnt >= 4일때 사용

                q.push({i, j});
                v.push_back({i, j});
                visited[i][j] = 1;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (out(nx, ny))
                            continue;

                        if ((field[nx][ny] == nowColor) && (visited[nx][ny] == 0))
                        {
                            q.push({nx, ny});
                            v.push_back({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }

                if (v.size() >= 4)
                {
                    // cout << "i: " << i << " j: " << j << " cnt: " << v.size() << "\n";
                    changed = true;

                    for (int k = 0; k < v.size(); k++)
                        field[v[k].first][v[k].second] = '.';
                }
            }
        }

    if (changed)
    {
        for (int i = 0; i < 6; i++)
        {
            int blockCnt = 0;
            for (int j = 11; j >= 0; j--)
            {
                if (field[j][i] != '.')
                {
                    if (field[11 - blockCnt][i] == '.')
                    {
                        field[11 - blockCnt][i] = field[j][i];
                        field[j][i] = '.';
                    }

                    blockCnt++;
                }
            }
        }
    }
}