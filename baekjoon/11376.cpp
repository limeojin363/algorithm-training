#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001];
vector<bool> visited;
vector<int> a_match;
vector<int> b_match;
int n, m;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (long unsigned int i = 0; i < adj[a].size(); i++) {
        int b = adj[a][i];
        if (b_match[b] == -1 || dfs(b_match[b])) {
            b_match[b] = a;
            a_match[a] = b;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int j; cin >> j;
        while (j--) {
            int o; cin >> o;
            adj[i].push_back(o);
        }
    }

    int ret = 0;
    a_match = vector<int>(n + 1, -1);
    b_match = vector<int>(m + 1, -1);
    for (int i = 1; i <= n; i++) {
        int j = 2;
        while (j--) {
            visited = vector<bool>(n + 1, false);
            if (dfs(i)) ret++;
        }
    }

    cout << ret;
}