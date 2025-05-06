#include <bits/stdc++.h>
#define EMPTY '.'
#define BODY 'o'
#define UP '^'
#define DOWN 'v'
#define RIGHT '>'
#define LEFT '<'

using namespace std;

char table[400][400];
int t;
int r, c;

int main() {
  cin >> t;

  while (t--) {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
      string temp;
      cin >> temp;

      for (int j = 0; j < c; j++)
        table[i][j] = temp[j];
    }

    int sol = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        if (i - 1 >= 0 && i + 1 < r)
          if (table[i - 1][j] == DOWN && table[i][j] == BODY && table[i + 1][j] == UP)
            sol++;
        if (j - 1 >= 0 && j + 1 < c)
          if (table[i][j - 1] == RIGHT && table[i][j] == BODY && table[i][j + 1] == LEFT)
            sol++;
      }

    cout << sol << endl;
  }


  return 0;
}