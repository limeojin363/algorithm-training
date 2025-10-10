#include <bits/stdc++.h>

using namespace std;

int n;

void preset() {
  cin >> n;
}

void solve() {
  int prev_max_sum[3] = { 0, 0, 0 };
  int prev_min_sum[3] = { 0, 0, 0 };

  int max_sum[3];
  int min_sum[3];

  int new_input[3];

  while (n--) {
    for (int i = 0; i < 3; i++)
      cin >> new_input[i];

    max_sum[0] = max({ prev_max_sum[0], prev_max_sum[1] }) + new_input[0];
    max_sum[1] = max({ prev_max_sum[0], prev_max_sum[1], prev_max_sum[2] }) + new_input[1];
    max_sum[2] = max({ prev_max_sum[1], prev_max_sum[2] }) + new_input[2];

    prev_max_sum[0] = max_sum[0];
    prev_max_sum[1] = max_sum[1];
    prev_max_sum[2] = max_sum[2];

    min_sum[0] = min({ prev_min_sum[0], prev_min_sum[1] }) + new_input[0];
    min_sum[1] = min({ prev_min_sum[0], prev_min_sum[1], prev_min_sum[2] }) + new_input[1];
    min_sum[2] = min({ prev_min_sum[1], prev_min_sum[2] }) + new_input[2];

    prev_min_sum[0] = min_sum[0];
    prev_min_sum[1] = min_sum[1];
    prev_min_sum[2] = min_sum[2];
  }

  cout << max({ prev_max_sum[0], prev_max_sum[1], prev_max_sum[2] }) << " " << min({ prev_min_sum[0], prev_min_sum[1], prev_min_sum[2] });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
