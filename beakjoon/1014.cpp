#include <bits/stdc++.h>
#define BROKEN 'x'
#define USABLE '.'

using namespace std;

void preset();
void solve();
int count1bit(int num);
int get_available_number(int col, int blocked);

int n, m;
int classroom[10][10];
int cache[10][1024];
int breakedOf[10];

void preset() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;

    for (int j = 0; j < m; j++)
      classroom[i][j] = s[j];
  }

  memset(breakedOf, 0, sizeof(breakedOf));


  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
      if (classroom[i][j] == BROKEN)
        breakedOf[j] |= (1 << i);

  memset(cache, -1, sizeof(cache));
}

void solve() {
  cout << get_available_number(0, breakedOf[0]) << "\n";
}

int count1bit(int num) {
  int ret = 0;
  while (num != 0) {
    ret += (num & 1);
    num >>= 1;
  }

  return ret;
}

int get_available_number(int col, int blocked) {
  // cout << col << " " << blocked << "\n";

  int& ret = cache[col][blocked];
  if (ret != -1) return ret;

  if (col == m - 1) {
    return ret = count1bit((~blocked) & ((1 << n) - 1));
  }

  ret = 0;

  for (int currFilled = 0; currFilled < (1 << n); currFilled++)
    if ((currFilled & blocked) == 0) {
      int nextBlocked = breakedOf[col + 1]
        | currFilled
        | (currFilled >> 1)
        | (currFilled << 1)
        & ((1 << n) - 1);

      ret = max(ret, count1bit(currFilled) + get_available_number(col + 1, nextBlocked));
    }

  return ret;
}

int main()
{
  int c; cin >> c;

  while (c--) {
    preset();
    solve();
  }
}