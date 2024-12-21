#include <bits/stdc++.h>
#define N_MAX 7000

using namespace std;

void recursively_draw(int y, int x, int size);

int n;
int filled[N_MAX][N_MAX];

void preset() {
  cin >> n;
  memset(filled, 0, sizeof(filled));
}

void solve() {
  recursively_draw(0, 0, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << (filled[i][j] ? '*' : ' ');

    cout << "\n";
  }
}

void recursively_draw(int y, int x, int size) {
  if (size == 3) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if ((i == 1) && (j == 1))
          continue;

        filled[y + i][x + j] = 1;
      }

    return;
  }

  int next_size = size / 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if ((i == 1) && (j == 1))
        continue;

      recursively_draw(y + i * next_size, x + j * next_size, next_size);
    }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
