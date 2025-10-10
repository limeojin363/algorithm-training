#include <bits/stdc++.h>
#define N_MAX 100001

using namespace std;

int n, k;
int visited[N_MAX];
int prev_pos[N_MAX];

void preset() {
  cin >> n >> k;
  memset(visited, -1, sizeof(visited));
}

void solve() {
  queue<int> q;
  visited[n] = 0;
  q.push(n);

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    int nx[] = { x + 1, x - 1, x * 2 };
    for (int i = 0; i < 3; i++) {
      if (nx[i] < 0 || nx[i] >= N_MAX)
        continue;
      if (visited[nx[i]] != -1)
        continue;

      visited[nx[i]] = visited[x] + 1;
      prev_pos[nx[i]] = x;
      q.push(nx[i]);
    }

  }

  cout << visited[k] << "\n";

  stack<int> res_stack;
  res_stack.push(k);
  int pos = k;
  while (pos != n) {
    pos = prev_pos[pos];
    res_stack.push(pos);
  }

  while (!res_stack.empty()) {
    cout << res_stack.top() << " ";
    res_stack.pop();
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
