#include <bits/stdc++.h>
#define N_MAX 101
#define SUM_MAX 100001

using namespace std;

int n, k;
int coin[N_MAX];
int dp[SUM_MAX];

void preset() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> coin[i];
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    int selected_coin_val = coin[i];

    for (int j = 0; j < SUM_MAX; j++) {
      if (j + selected_coin_val > SUM_MAX) {
        break;
      }
      dp[j + selected_coin_val] += dp[j];
    }
  }

  cout << dp[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
