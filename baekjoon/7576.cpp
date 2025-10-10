#include <iostream>
#include <string.h>
#include <queue>
#define MAX_HEIGHT 1001
#define MAX_WIDTH 1001

using namespace std;
using pos = pair<int, int>;

int m, n;
int box[MAX_HEIGHT][MAX_WIDTH];
int visit_info[MAX_HEIGHT][MAX_WIDTH];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool out(int y, int x) {
  return y < 0 || x < 0 || y >= n || x >= m;
}

void get_input() {
  cin >> m >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> box[i][j];
}

void solve() {
  memset(visit_info, -1, sizeof(visit_info));
  queue<pos> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (box[i][j] == 1) {
        visit_info[i][j] = 0;
        q.push(make_pair(i, j));
      }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int direction = 0; direction < 4; direction++) {
      int ny = y + dy[direction];
      int nx = x + dx[direction];
      if (!out(ny, nx) && box[ny][nx] == 0 && visit_info[ny][nx] == -1) {
        q.push({ ny, nx });
        visit_info[ny][nx] = visit_info[y][x] + 1;
      }
    }
  }

  int complete_time = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (visit_info[i][j] == -1 && box[i][j] == 0) {
        cout << -1;
        return;
      }
      complete_time = max(complete_time, visit_info[i][j]);
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
