#include <bits/stdc++.h>
#define HEIGHT_MAX 1024
#define WIDTH_MAX 2048

using namespace std;

int n;
int res[HEIGHT_MAX][WIDTH_MAX];

void fill(int y, int x, int size);

void preset() {
  cin >> n;
}

void fill(int y, int x, int size) {
  if (size == 2) {
    res[y][x] = 1;
    return;
  }

  int how_many_doubled = log2(size);
  // 짝수 -> 역삼각형
  if (how_many_doubled % 2 == 0) {
    for (int i = 0; i < size - 1; i++)
    {
      res[y - i][x - i] = 1;
      res[y - i][x + i] = 1;
      res[y - size + 2][x - i] = 1;
      res[y - size + 2][x + i] = 1;
    }
    fill(y - size + 3, x, size / 2);
  }
  // 홀수 -> 그냥삼각형
  else {
    for (int i = 0; i < size - 1; i++)
    {
      res[y + i][x - i] = 1;
      res[y + i][x + i] = 1;
      res[y + size - 2][x - i] = 1;
      res[y + size - 2][x + i] = 1;
    }
    fill(y + size - 3, x, size / 2);
  }
}

void print() {
  if (n % 2 == 0)
    for (int i = 0; i < pow(2, n) - 1; i++) {
      for (int j = 0; j < 2 * pow(2, n) - i - 3; j++)
        cout << (res[i][j] ? '*' : ' ');
      cout << "\n";
    }
  else
    for (int i = 0; i < pow(2, n) - 1; i++) {
      for (int j = 0; j < pow(2, n) + i - 1; j++)
        cout << (res[i][j] ? '*' : ' ');
      cout << "\n";
    }
}

void solve() {
  memset(res, 0, sizeof(res));
  int doubled = pow(2, n);
  int start_y = (n % 2 == 0) ? doubled - 2 : 0;
  int start_x = doubled - 2;
  fill(start_y, start_x, doubled);

  print();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
