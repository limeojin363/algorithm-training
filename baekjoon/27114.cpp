#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 9999999

using namespace std;

int dp(int pose, int remaining);

int a, b, c, k;
// 원래 위치(0)에서 시계방향으로 돌때마다 1 증가
int cache[4][1000001];

int dp(int pose, int remaining) {
  if (remaining < 0)
    return MAX;
  if (remaining == 0)
  {
    if (pose != 0)
      return MAX;
    return 0;
  }

  if (cache[pose][remaining] != -1)
    return cache[pose][remaining];

  return cache[pose][remaining] = 1 + min({ dp((pose + 3) % 4, remaining - a), dp((pose + 1) % 4, remaining - b), dp((pose + 2) % 4, remaining - c) });
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(cache, -1, sizeof(cache));

  cin >> a >> b >> c >> k;
  int ret = dp(0, k);
  if (ret >= MAX)
    cout << -1;
  else
    cout << ret;
}
