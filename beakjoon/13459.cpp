#include <iostream>
#include <string>
#include <string.h>
#include <queue> 
#include <tuple>
#define MAX_HEIGHT 11
#define MAX_WIDTH 11
#define WALL '#'
#define EMPTY '.'
#define RED_BEAD 'R'
#define BLUE_BEAD 'B'
#define HOLE 'O'
#define D_NUM 4

using namespace std;
using bead_position = tuple<int, int>;
using position_combination = tuple<int, int, int, int>;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };
int n, m;
char board[MAX_HEIGHT][MAX_WIDTH];
// visit_info[y1][x1][y2][x2]에서 y1, x1는 빨강, y2, x2는 파랑
int visit_info[MAX_HEIGHT][MAX_WIDTH][MAX_HEIGHT][MAX_WIDTH];
bead_position red_position;
bead_position blue_position;

void get_input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string str; cin >> str;
    for (int j = 0; j < m; j++)
    {
      board[i][j] = str[j];
      if (board[i][j] == RED_BEAD)
        red_position = make_tuple(i, j);
      if (board[i][j] == BLUE_BEAD)
        blue_position = make_tuple(i, j);
    }
  }
}

bool is_red_moves_first(int y1, int x1, int y2, int x2, int di) {
  int selected_dy = dy[di], selected_dx = dx[di];
  if (selected_dy != 0) {
    bool is_blue_higher = (y2 - y1) > 0;
    bool is_going_down = selected_dy < 0;

    return is_going_down == is_blue_higher;
  }
  else {
    bool is_blue_righter = (x2 - x1) > 0;
    bool is_going_left = selected_dx < 0;

    return is_blue_righter == is_going_left;
  }
}

void solve() {
  memset(visit_info, -1, sizeof(visit_info));

  queue<position_combination> q;
  int y1, x1, y2, x2;
  tie(y1, x1) = red_position;
  tie(y2, x2) = blue_position;
  visit_info[y1][x1][y2][x2] = 0;
  q.push(make_tuple(y1, x1, y2, x2));

  while (!q.empty()) {
    int y1, x1, y2, x2;
    tie(y1, x1, y2, x2) = q.front();
    if (visit_info[y1][x1][y2][x2] == 10) {
      cout << 0;
      return;
    }
    q.pop();

    cout << y1 << " " << x1 << " " << y2 << " " << x2 << " \n";

    for (int di = 0; di < D_NUM; di++) {
      if (is_red_moves_first(y1, x1, y2, x2, di)) {
        // 빨간 구슬을, 계산된 다음 위치가 벽이나 구멍일 때까지 이동
        int ny1 = y1, nx1 = x1;
        while (!
          (board[ny1 + dy[di]][nx1 + dx[di]] == WALL
            || board[ny1 + dy[di]][nx1 + dx[di]] == HOLE)) {
          ny1 += dy[di];
          nx1 += dx[di];
        }
        int ny2 = y2, nx2 = x2;
        // 파란 구슬을, 계산된 다음 위치가 벽이나 구멍, 빨간 구슬일 때까지 이동
        while (!(board[ny2 + dy[di]][nx2 + dx[di]] == WALL
          || board[ny2 + dy[di]][nx2 + dx[di]] == HOLE
          || ((ny2 + dy[di] == ny1) && (nx2 + dx[di] == nx1)))
          ) {
          ny2 += dy[di];
          nx2 += dx[di];
        }

        bool two_meets = (ny2 + dy[di] == ny1) && (nx2 + dx[di] == nx1);

        char red_block_component = board[ny1 + dy[di]][nx1 + dx[di]];
        char blue_block_component = board[ny2 + dy[di]][nx2 + dx[di]];

        if (blue_block_component == HOLE) {
          // 
        }
        else if (red_block_component == HOLE) {
          if (two_meets) {
            // 
          }
          else {
            cout << 1;
            return;
          }
        }
        else {
          if (visit_info[ny1][nx1][ny2][nx2] == -1) {
            visit_info[ny1][nx1][ny2][nx2] = visit_info[y1][x1][y2][x2] + 1;
            q.push(make_tuple(ny1, nx1, ny2, nx2));
          }
        }
      }
      else {
        // 파란 구슬을, 계산된 다음 위치가 벽이나 구멍일 때까지 이동
        int ny2 = y2, nx2 = x2;
        while (!
          (board[ny2 + dy[di]][nx2 + dx[di]] == WALL || board[ny2 + dy[di]][nx2 + dx[di]] == HOLE
            )
          ) {
          ny2 += dy[di];
          nx2 += dx[di];
        }
        // 빨간 구슬을, 계산된 다음 위치가 벽이나 구멍, 파란 구슬일 때까지 이동
        int ny1 = y1, nx1 = x1;
        while (!(board[ny1 + dy[di]][nx1 + dx[di]] == WALL
          || board[ny1 + dy[di]][nx1 + dx[di]] == HOLE
          || ((ny1 + dy[di] == ny2) && (nx1 + dx[di] == nx2)))
          ) {
          ny1 += dy[di];
          nx1 += dx[di];
        }
        bool two_meets = (ny1 + dy[di] == ny2) && (nx1 + dx[di] == nx2);

        char red_block_component = board[ny1 + dy[di]][nx1 + dx[di]];
        char blue_block_component = board[ny2 + dy[di]][nx2 + dx[di]];

        if (red_block_component == HOLE) {
          // 
        }
        else if (blue_block_component == HOLE) {
          if (two_meets) {
            // 
          }
          else {
            cout << 1;
            return;
          }
        }
        else {
          if (visit_info[ny1][nx1][ny2][nx2] == -1) {
            visit_info[ny1][nx1][ny2][nx2] = visit_info[y1][x1][y2][x2] + 1;
            q.push(make_tuple(ny1, nx1, ny2, nx2));
          }
        }
      }
    }
  }

  cout << 0;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  get_input();
  solve();
}
