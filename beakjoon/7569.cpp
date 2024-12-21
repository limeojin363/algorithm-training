#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>
#define MAX_X 101
#define MAX_Y 101
#define MAX_Z 101

using namespace std;
using pos = tuple<int, int, int>;

int m, n, h;
int box[MAX_X][MAX_Y][MAX_Z];
int visit_info[MAX_X][MAX_Y][MAX_Z];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

bool out(int y, int x, int z) {
  return z < 0 || z >= h || y < 0 || x < 0 || y >= n || x >= m;
}

void get_input() {
  cin >> m >> n >> h;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> box[i][j][k];
}

void solve() {
  memset(visit_info, -1, sizeof(visit_info));
  queue<pos> q;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (box[i][j][k] == 1) {
          visit_info[i][j][k] = 0;
          q.push(make_tuple(i, j, k));
        }

  while (!q.empty()) {
    int y, x, z;
    tie(y, x, z) = q.front();
    q.pop();

    for (int direction = 0; direction < 6; direction++) {
      int ny = y + dy[direction];
      int nx = x + dx[direction];
      int nz = z + dz[direction];
      if (!out(ny, nx, nz) && (box[ny][nx][nz] == 0) && (visit_info[ny][nx][nz] == -1)) {
        q.push(make_tuple(ny, nx, nz));
        visit_info[ny][nx][nz] = visit_info[y][x][z] + 1;
      }
    }
  }

  int complete_time = 0;
  for (int k = 0; k < h; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (visit_info[i][j][k] == -1 && box[i][j][k] == 0) {
          cout << -1;
          return;
        }

        complete_time = max(complete_time, visit_info[i][j][k]);
      }

  cout << complete_time;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  get_input();
  solve();
}
