#include <iostream>
#include <string.h>

using namespace std;

long long cache[4][10001];

long long dp(int a, int b) {
  long long& ret = cache[a][b];
  if (ret != -1)
    return ret;

  if (b < 0)
    return ret = 0;
  if (b == 0)
    return ret = 1;

  switch (a) {
  case 3:
    return ret = dp(3, b - 3) + dp(2, b - 2) + dp(1, b - 1);
  case 2:
    return ret = dp(2, b - 2) + dp(1, b - 1);
  case 1:
    return ret = dp(1, b - 1);
  default:
    return ret = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    memset(cache, -1, sizeof(cache));

    int n; cin >> n;
    cout << dp(3, n) << "\n";
  }
}
