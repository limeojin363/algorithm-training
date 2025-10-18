#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int a_match[201];
int b_match[201];
bool adj[201][201];
bool visited[201];

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;

    for (int b = 0; b < m; b++)
        if (adj[a][b])
            if (b_match[b] == -1 || dfs(b_match[b]))
            {
                b_match[b] = a;
                a_match[a] = b;
                return true;
            }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        for (int j = 0; j < t; j++) {
            int k; cin >> k;
            adj[i][k - 1] = true;
        }
    }

    memset(a_match, -1, sizeof(a_match));
    memset(b_match, -1, sizeof(b_match));
    int size = 0;
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i))
            size++;
    }

    cout << size;
}
