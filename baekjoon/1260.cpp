// https://www.acmicpc.net/problem/1260
// Solved: 2025-10-12

#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#define NODE_MAX 1001

using namespace std;

void dfs(int node);
void print_dfs();
void print_bfs();

vector<int> g[NODE_MAX];
int visited[NODE_MAX];
int n, m, v;

void dfs(int node) {
    assert(visited[node] == -1);
    visited[node] = 1;
    cout << node << " ";

    for (int i = 0; i < g[node].size(); i++) {
        int node1 = g[node][i];
        
        if (visited[node1] != -1) continue;
        dfs(node1);
    }
}

void print_dfs() {
    memset(visited, -1, sizeof(visited));

    dfs(v);
}

void print_bfs() {
    memset(visited, -1, sizeof(visited));

    queue<int> q;
    q.push(v);
    visited[v] = 1;
    cout << v << " ";

    while (!q.empty()) {
        int node1 = q.front();
        q.pop();
        for (int i = 0; i < g[node1].size(); i++) {
            int node2 = g[node1][i];

            if (visited[node2] != -1) continue;
            
            q.push(node2);
            visited[node2] = 1;
            cout << node2 << " ";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    
    print_dfs();
    cout << "\n";
    print_bfs();
}