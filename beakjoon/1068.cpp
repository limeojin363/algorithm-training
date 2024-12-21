#include <bits/stdc++.h>
#define N_MAX 51

using namespace std;

int n;
int parent[N_MAX];
int root;
vector<int> children[N_MAX];
int to_delete;

void preset() {
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> parent[i];
    if (parent[i] == -1)
      root = i;
    else
      children[parent[i]].push_back(i);
  }
  cin >> to_delete;
}

void solve() {
  int leaf_cnt = 0;
  for (int i = 0; i < n; i++)
    if (children[i].size() == 0 || (children[i].size() == 1 && children[i][0] == to_delete)) {
      int now_node = i;
      bool is_leaf = true;
      while (1) {
        if (now_node == -1)
          break;
        if (now_node == to_delete)
        {
          is_leaf = false;
          break;
        }
        now_node = parent[now_node];
      }
      if (is_leaf) leaf_cnt++;
    }

  cout << leaf_cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
