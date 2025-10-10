#include <iostream>
#include <string.h>

using namespace std;

const long long MIN = -10000LL * 10001 * 20001 / 6;

int n;
int notes[1000];
long long cache[1000][1000][3];

long long dp(int idx, int combo, int missed);

long long dp(int idx, int combo, int missed) {
  if (idx == n) return 0;

  long long& ret = cache[idx][combo][missed];
  if (ret != MIN)
    return ret;

  if (missed == 2) {
    return ret = notes[idx] * (combo + 1) + dp(idx + 1, combo + 1, 0);
  }

  return ret = max(notes[idx] * (combo + 1) + dp(idx + 1, combo + 1, 0),
    dp(idx + 1, 0, missed + 1));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> notes[i];

  for (int i = 0; i < 1000; i++)
    for (int j = 0; j < 1000; j++)
      for (int k = 0; k < 3; k++)
        cache[i][j][k] = MIN;
  cout << max(dp(0, 0, 0), (long long)0);

  return 0;
}