#include <iostream>
#include <string.h>
#define MIN -999999999

using namespace std;

int dp(int idx, int remaining);

int n, k;
int cache[1001][10001];
int l[1001];
int t[1001];

int dp(int idx, int remaining) {
  int& ret = cache[idx][remaining];
  if (ret != -1)
    return ret;

  if (idx == k)
    return 0;

  if (remaining >= t[idx])
    return ret = max(l[idx] + dp(idx + 1, remaining - t[idx]), dp(idx + 1, remaining));
  return ret = dp(idx + 1, remaining);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++)
    cin >> l[i] >> t[i];

  memset(cache, -1, sizeof(cache));
  cout << dp(0, n);
}
