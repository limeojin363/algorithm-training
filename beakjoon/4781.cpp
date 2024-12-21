#include <iostream>
#include <string.h>

using namespace std;

int n;
int mm;
int c[5001];
int pp[5001];
int cache[5001][10001];

int dp(int idx, int remaining) {
  if (idx == n)
    return 0;

  int& ret = cache[idx][remaining];
  if (ret != -1)
    return ret;

  ret = 0;
  for (int i = 0; pp[idx] * i <= remaining; i++)
    ret = max(ret, dp(idx + 1, remaining - pp[idx] * i) + c[idx] * i);

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (1) {
    double m;
    cin >> n >> m;
    mm = (m * 100.0);
    if (n == 0) break;

    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < n; i++) {
      double p;
      cin >> c[i] >> p;
      pp[i] = (p * 100.0);
    }

    cout << dp(0, mm) << "\n";
  }
}
