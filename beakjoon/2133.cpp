#include <bits/stdc++.h>
#define N_MAX 31

using namespace std;

long long cache[N_MAX];

int n;

void preset() {
  cin >> n;
}

long long dp(int w) {
  if (w % 2 != 0)
    return 0;

  if (w == 0)
    return 1;

  long long& ret = cache[w];

  if (ret != -1)
    return ret;

  ret = 0;
  int extended_comb_width = w; // 넓게 잡는 경우
  while (extended_comb_width > 2)
  {
    ret += 2 * dp(w - extended_comb_width);
    extended_comb_width -= 2;
  }

  return ret += 3 * dp(w - 2);
}

void solve() {
  memset(cache, -1, sizeof(cache));
  cout << dp(n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
