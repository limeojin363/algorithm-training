#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> virusList;
vector<vector<pair<int, int>>> virusCombination;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                virusList.push_back({i, j});
        }

    vector<int> ind;
    for (int i = 0; i < m; i++)
        ind.push_back(1);
    for (int i = 0; i < virusList.size() - m; i++)
        ind.push_back(0);
    sort(ind.begin(), ind.end());

    do
    {
        vector<pair<int, int>> v = {};

        for (int i = 0; i < ind.size(); i++)
        {
            if (ind[i] == 1)
                v.push_back(virusList[i]);
        }
        virusCombination.push_back(v);

    } while (next_permutation(ind.begin(), ind.end()));

    // for (int i = 0; i < virusCombination.size(); i++)
    // {
    //     for (int j = 0; j < virusCombination[i].size(); j++)
    //         cout << virusCombination[i][j].first << " " << virusCombination[i][j].second << " ";
    //     cout << "\n";
    // }

    int ans = 123456789;

    for (int i = 0; i < virusCombination.size(); i++)
    {
        int visited[51][51];
        int nowMax = 0;

        memset(visited, -1, sizeof(visited));

        queue<pair<int, int>> q;
        for (int j = 0; j < virusCombination[i].size(); j++)
        {
            q.push(virusCombination[i][j]);
            visited[virusCombination[i][j].first][virusCombination[i][j].second] = 0;
        }

        for (int j = 0; j < virusList.size(); j++)
            if (visited[virusList[j].first][virusList[j].second] == -1)
                visited[virusList[j].first][virusList[j].second] = -2; // 비활성 바이러스

        while (!q.empty())
        {
            int x, y;
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (arr[nx][ny] == 1)
                    continue;

                if (visited[nx][ny] == -1)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                    nowMax = max(nowMax, visited[nx][ny]);
                }
                else if (visited[nx][ny] == -2)
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int flag = 1;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if ((visited[j][k] == -1) && (arr[j][k] != 1))
                    flag = 0;

        if (!flag)
            continue;

        ans = min(nowMax, ans);
    }

    cout << (ans == 123456789 ? -1 : ans);
}