#include <iostream>
#include <string.h>

using namespace std;

int dp(int idx, int remaining_time);

int n, t;
int k[101];
int s[101];
int cache[101][10001];

int dp(int idx, int remaining_time) {
  int& ret = cache[idx][remaining_time];
  if (ret != -1)
    return ret;

  if (idx == n)
    return ret = 0;

  if (remaining_time >= k[idx])
    return ret = max(dp(idx + 1, remaining_time), dp(idx + 1, remaining_time - k[idx]) + s[idx]);

  return ret = dp(idx + 1, remaining_time);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> t;

  for (int i = 0; i < n; i++)
    cin >> k[i] >> s[i];


  memset(cache, -1, sizeof(cache));
  cout << dp(0, t);
}
