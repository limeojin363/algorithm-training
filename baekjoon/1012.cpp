// https://www.acmicpc.net/problem/1012
// solved: 2025-10-11

#include <iostream>
#include <cstring>
#include <queue>
#define WIDTH_MAX 50
#define HEIGHT_MAX 50

using namespace std;

int m, n, k;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int planted[HEIGHT_MAX][WIDTH_MAX];
int visited[HEIGHT_MAX][WIDTH_MAX];

bool out(int y, int x) {
    return y < 0 || x < 0 || y >= n || x >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        memset(planted, 0, sizeof(planted));
        memset(visited, 0, sizeof(visited));
        cin >> m >> n >> k;
        while (k--) {
            int x, y;
            cin >> x >> y;
            planted[y][x] = 1;
        }

        int last_visited = 0;
        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++) {
                if (visited[y][x] > 0) continue;
                if (!planted[y][x]) continue;
                
                queue<pair<int,int>> q;
                
                visited[y][x] = ++last_visited;
                q.push(make_pair(y, x));

                while (!q.empty()) {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    // cout << "DEBUGGING_1 " << cy << " " << cx << " " << last_visited << "\n";

                    for (int i = 0; i < 4; i++) {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];

                        if (out(ny, nx)) continue;
                        if (visited[ny][nx] > 0) continue;
                        if (!planted[ny][nx]) continue;

                        visited[ny][nx] = visited[y][x];
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        cout << last_visited << "\n";
    }

}