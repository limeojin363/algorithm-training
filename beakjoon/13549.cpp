#include <bits/stdc++.h>
#define N_MAX 100001

using namespace std;

int visited[N_MAX];
int n, k;
int dx[] = { -1, 1 };

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

    // 순간이동
    int nx = x * 2;

    if (!(nx >= N_MAX || nx < 0 || (visited[nx] != -1)))
    {
      visited[nx] = visited[x];
      q.push(nx);
    }

    // 걷기
    for (int i = 0; i < 2; i++) {
      int nx = x + dx[i];

      if (nx >= N_MAX || nx < 0)
        continue;
      if (visited[nx] != -1)
        continue;

      visited[nx] = visited[x] + 1;
      q.push(nx);
    }

  }

  cout << visited[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
