#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, r, q;
vector<int> graph[100001];
int cache[100001];

int dp(int x, int previous);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(cache, -1, sizeof(cache));
    
    dp(r, 0);

    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;
        cout << dp(u, 0) << "\n";
    }
}

int dp(int x, int previous)
{
    int &ret = cache[x];

    if (ret != -1)
        return ret;

    ret = 1;
    for (int i = 0; i < graph[x].size(); i++)
        if (graph[x][i] != previous)
            ret += dp(graph[x][i], x);

    return ret;
}