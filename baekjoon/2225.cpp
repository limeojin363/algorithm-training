#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int n, k;
int cache[201][201];

void preset() {
  cin >> n >> k;
  memset(cache, -1, sizeof(cache));
}

int dp(int remaining_count, int remaining_value) {
  int& ret = cache[remaining_count][remaining_value];
  if (ret != -1)
    return ret;

  if (remaining_value == 0)
    return (ret = 1);

  if (remaining_count == 0)
    return (ret = 0);

  ret = 0;
  for (int i = 0; i <= remaining_value; i++)
    ret += (dp(remaining_count - 1, remaining_value - i) % MOD);

  return (ret % MOD);
}

void solve() {
  cout << (dp(k, n) % MOD) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
