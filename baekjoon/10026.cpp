#include <bits/stdc++.h>
#define N_MAX 101
#define R 'R'
#define G 'G'
#define B 'B'

using namespace std;

int n;
char grid[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void preset() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str; cin >> str;
    for (int j = 0; j < n; j++)
      grid[i][j] = str[j];
  }
}

bool out(int y, int x) {
  return y < 0 || x < 0 || y >= n || x >= n;
}

void bfs1() {
  memset(visited, 0, sizeof(visited));

  int graph_num = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (visited[i][j] == 0) {
        int selected_color = grid[i][j];

        queue<pair<int, int>> q;
        visited[i][j] = ++graph_num;
        q.push({ i, j });

        while (!q.empty()) {
          int y = q.front().first;
          int x = q.front().second;
          q.pop();

          for (int k = 0; k < n; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (out(ny, nx))
              continue;
            if (visited[ny][nx] != 0)
              continue;
            if (selected_color != grid[ny][nx])
              continue;

            visited[ny][nx] = visited[i][j];
            q.push({ ny, nx });
          }
        }
      }

  cout << graph_num;
}

void bfs2() {
  memset(visited, 0, sizeof(visited));

  int graph_num = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (visited[i][j] == 0) {
        int selected_color = grid[i][j];

        queue<pair<int, int>> q;
        visited[i][j] = ++graph_num;
        q.push({ i, j });

        while (!q.empty()) {
          int y = q.front().first;
          int x = q.front().second;
          q.pop();

          for (int k = 0; k < n; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (out(ny, nx))
              continue;
            if (visited[ny][nx] != 0)
              continue;
            if (
              (selected_color != grid[ny][nx]) &&
              (selected_color == B || grid[ny][nx] == B)
              )
              continue;

            visited[ny][nx] = visited[i][j];
            q.push({ ny, nx });
          }
        }
      }

  cout << graph_num;
}

void solve() {
  bfs1();
  cout << " ";
  bfs2();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
