// 9663.cpp

#include <bits/stdc++.h>
#define SIDE_MAXLEN 15

using namespace std;

// N * N에서 N개의 퀸 -> 한 행에 퀸이 한개 이상 있어야 한다..

int col[SIDE_MAXLEN]; // col[col_num] = row_num: col_num열 row_num행에 퀸이 채워졌다는 뜻
int n;

void preset() {
  cin >> n;
}

// 백트래킹
int go(int col_num) {
  if (col_num == n)
    return 1;

  int ret = 0;

  for (int row_num = 0; row_num < n; row_num++) {
    bool playable = true;

    for (int prev_col_num = col_num - 1; prev_col_num >= 0; prev_col_num--) {

      if (
        (abs(prev_col_num - col_num) == abs(col[prev_col_num] - row_num)) // 대각선 케이스
        || (row_num == col[prev_col_num]) // 같은 행 케이스
        )
      {
        playable = false;
        break;
      }

    }

    if (!playable)
      continue;

    col[col_num] = row_num;
    ret += go(col_num + 1);
    col[col_num] = -1;

  }

  return ret;
}

void solve() {
  memset(col, -1, sizeof(col));
  cout << go(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
