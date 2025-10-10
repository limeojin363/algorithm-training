#include <iostream>
#include <string.h>
#include <string>
#include <queue>

#define WALL '#'
#define ME '@'
#define EMPTY '.'
#define FIRE '*'
#define IMPOSSIBLE "IMPOSSIBLE"

using namespace std;

int w, h;
char building_input[1001][1001];
int time_to_burn[1001][1001];
int time_to_escape[1001][1001];
typedef struct Bfs_q_node {
  int y, x;
} Bfs_q_node;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool out(int y, int x) {
  return x < 0 || y < 0 || x >= w || y >= h;
}

void receive_input() {
  cin >> w >> h;

  for (int y = 0; y < h; y++) {
    string s; cin >> s;
    for (int x = 0; x < w; x++)
      building_input[y][x] = s[x];
  }

}

void calc_time_to_burn() {
  memset(time_to_burn, -1, sizeof(time_to_burn));
  queue<Bfs_q_node> q;

  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (building_input[y][x] == FIRE)
      {
        time_to_burn[y][x] = 0;
        q.push({ y, x });
      }

  while (!q.empty()) {
    Bfs_q_node node = q.front();
    q.pop();

    int x = node.x;
    int y = node.y;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (out(ny, nx))
        continue;
      if (time_to_burn[ny][nx] != -1)
        continue;
      if (building_input[ny][nx] == WALL)
        continue;

      time_to_burn[ny][nx] = time_to_burn[y][x] + 1;
      q.push({ ny, nx });
    }
  }
}

void calc_time_to_escape() {
  memset(time_to_escape, -1, sizeof(time_to_escape));
  queue<Bfs_q_node> q;

  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (building_input[y][x] == ME)
      {
        time_to_escape[y][x] = 0;
        q.push({ y, x });
      }

  while (!q.empty()) {
    Bfs_q_node node = q.front();
    q.pop();

    int x = node.x;
    int y = node.y;
    int before_time = time_to_escape[y][x];
    int after_time = before_time + 1;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (out(ny, nx))
      {
        cout << after_time << "\n";
        return;
      }
      if (building_input[ny][nx] == WALL)
        continue;
      if ((time_to_burn[ny][nx] != -1) && (after_time >= time_to_burn[ny][nx]))
        continue;
      if (time_to_escape[ny][nx] != -1)
        continue;

      time_to_escape[ny][nx] = time_to_escape[y][x] + 1;
      q.push({ ny, nx });
    }
  }

  cout << IMPOSSIBLE << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tc_cnt; cin >> tc_cnt;
  while (tc_cnt--) {
    receive_input();
    calc_time_to_burn();
    calc_time_to_escape();
  }
}
