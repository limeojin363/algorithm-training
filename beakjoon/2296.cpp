#include <iostream>
#include <string.h>
#include <algorithm>
#include <tuple>

using namespace std;


int n;


struct Building {
  int x, y, c;
};

Building buildings[1001];
int cache1[1001][1001];
int cache2[1001][1001];

// 우상향
int dp1(int nowIdx, int recentIdx);
// 우하향
int dp2(int nowIdx, int recentIdx);

int dp1(int nowIdx, int recentIdx) {
  if (nowIdx == n + 1) return 0;

  int& ret = cache1[nowIdx][recentIdx];
  if (ret != -1) return ret;

  if (buildings[nowIdx].y > buildings[recentIdx].y)
    return ret = max(dp1(nowIdx + 1, recentIdx), buildings[nowIdx].c + dp1(nowIdx + 1, nowIdx));

  return ret = dp1(nowIdx + 1, recentIdx);
}

int dp2(int nowIdx, int recentIdx) {
  if (nowIdx == n + 1) return 0;

  int& ret = cache2[nowIdx][recentIdx];
  if (ret != -1) return ret;

  if (buildings[nowIdx].y < buildings[recentIdx].y)
    return ret = max(dp2(nowIdx + 1, recentIdx), buildings[nowIdx].c + dp2(nowIdx + 1, nowIdx));

  return ret = dp2(nowIdx + 1, recentIdx);
}

bool comp(Building a, Building b) {
  return a.x < b.x;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> buildings[i].x >> buildings[i].y >> buildings[i].c;

  for (int i = 0; i < 1001; i++)
    for (int j = 0; j < 1001; j++)
      cache1[i][j] = cache2[i][j] = -1;

  sort(buildings + 1, buildings + 1 + n, comp);

  int res;
  buildings[0].y = 0;
  res = dp1(1, 0);
  buildings[0].y = 1000000001;
  res = max(res, dp2(1, 0));

  cout << res;

  return 0;
}