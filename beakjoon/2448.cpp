#include <bits/stdc++.h>
#define HEIGHT_MAX 3100
#define WIDTH_MAX 6200

using namespace std;

int res[HEIGHT_MAX][WIDTH_MAX];
int n;

void preset() {
  cin >> n;
  memset(res, 0, sizeof(res));
}

void recursively_set_pos(int y, int x, int height) {
  if (height == 3) {
    res[y][x] = res[y + 1][x - 1] = res[y + 1][x + 1] = res[y + 2][x - 2]
      = res[y + 2][x - 1] = res[y + 2][x] = res[y + 2][x + 1] = res[y + 2][x + 2]
      = 1;
    return;
  }

  int next_height = height / 2;
  recursively_set_pos(y, x, height / 2);
  recursively_set_pos(y + next_height, x - next_height, height / 2);
  recursively_set_pos(y + next_height, x + next_height, height / 2);
}

void set_res() {
  recursively_set_pos(0, n - 1, n);
}

void print_sol() {
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n * 2; x++)
      cout << (res[y][x] ? '*' : ' ');
    cout << "\n";
  }
}

void solve() {
  set_res();
  print_sol();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
