#include <bits/stdc++.h>
#define CHN_MAX 1000001

using namespace std;

int n, m;
int is_broken[10];
int first_dist[CHN_MAX];

vector<int> apart(int num) {
  vector<int> ret = {};

  if (num == 0) {
    ret.push_back(0);

    return ret;
  }

  while (num != 0) {
    int remaining = num % 10;
    ret.push_back(remaining);
    num /= 10;
  }

  return ret;
}

void preset() {
  cin >> n >> m;
  memset(is_broken, 0, sizeof(is_broken));

  for (int i = 0; i < m; i++) {
    int input; cin >> input;
    is_broken[input] = 1;
  }
}

void solve() {
  memset(first_dist, -1, sizeof(first_dist));

  first_dist[100] = 0;
  for (int i = 0; i < CHN_MAX; i++) {
    if (i == 100)
      continue;

    int is_now_reachable = 1;

    vector<int> nums = apart(i);
    for (int j = 0; j < nums.size(); j++) {
      int now_num = nums[j];
      if (is_broken[now_num]) {
        is_now_reachable = 0;
        break;
      }
    }

    if (is_now_reachable)
      first_dist[i] = nums.size();
  }

  int sol = CHN_MAX;
  for (int i = 0; i < CHN_MAX; i++)
    if (first_dist[i] != -1)
      sol = min(sol, abs(i - n) + first_dist[i]);

  cout << sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
