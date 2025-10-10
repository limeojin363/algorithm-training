#include <iostream>
#include <string>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        char arr[31][31][31];
        int visited[31][31][31];
        memset(visited, -1, sizeof(visited));
        tuple<int, int, int> start;
        tuple<int, int, int> end;

        int l, r, c;
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
            {
                string row;
                cin >> row;
                for (int k = 0; k < c; k++)
                {
                    arr[i][j][k] = row[k];

                    if (arr[i][j][k] == 'S')
                        start = {i, j, k};
                    if (arr[i][j][k] == 'E')
                        end = {i, j, k};
                }
            }

        queue<tuple<int, int, int>> q;

        int start_x, start_y, start_z;
        tie(start_x, start_y, start_z) = start;

        visited[start_x][start_y][start_z] = 0;
        q.push({start_x, start_y, start_z});
        while (!q.empty())
        {
            int x, y, z;
            tie(x, y, z) = q.front();
            q.pop();

            tuple<int, int, int> list[6] = {
                {x - 1, y, z},
                {x + 1, y, z},
                {x, y - 1, z},
                {x, y + 1, z},
                {x, y, z - 1},
                {x, y, z + 1},
            };
            for (int i = 0; i < 6; i++)
            {
                int nx, ny, nz;
                tie(nx, ny, nz) = list[i];

                if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c)
                    continue;
                if (visited[nx][ny][nz] != -1)
                    continue;
                if (arr[nx][ny][nz] == '#')
                    continue;

                visited[nx][ny][nz] = visited[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }

        int end_x, end_y, end_z;
        tie(end_x, end_y, end_z) = end;

        if (visited[end_x][end_y][end_z] == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << visited[end_x][end_y][end_z] << " minute(s).\n";
    }
}
