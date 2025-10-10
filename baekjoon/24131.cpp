#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX 100001

using namespace std;

class Node
{
public:
    vector<int> in;
    vector<int> out;
};

int v, e;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

int SCC_num[MAX];
Node SCC_graph[MAX];
int visited[MAX];

int dfs(int x);
bool cmp(vector<int> a, vector<int> b);
void make_graph();
void go_forward(int x);
void go_behind(int x);

int dfs(int x)
{
    d[x] = ++id; // 노드 고유번호 할당
    s.push(x);

    int parent = d[x];
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (d[y] == 0) // 방문하지 않은 이웃
            parent = min(parent, dfs(y));
        else if (!finished[y]) // 처리중인 이웃
            parent = min(parent, d[y]);
    }

    if (parent == d[x]) // 자기 자신이 부모 노드
    {
        vector<int> scc;
        while (1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x)
                break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

void make_graph()
{
    for (int i = 0; i < SCC.size(); i++)
    {
        for (int j = 0; j < SCC[i].size(); j++)
            for (int k = 0; k < a[SCC[i][j]].size(); k++)
            {
                if (i == SCC_num[a[SCC[i][j]][k]])
                    continue;
                SCC_graph[i].out.push_back(SCC_num[a[SCC[i][j]][k]]);
                SCC_graph[SCC_num[a[SCC[i][j]][k]]].in.push_back(i);
            }
    }

    for (int i = 0; i < SCC.size(); i++)
    {
        SCC_graph[i].out.erase(unique(SCC_graph[i].out.begin(), SCC_graph[i].out.end()), SCC_graph[i].out.end());
        SCC_graph[i].in.erase(unique(SCC_graph[i].in.begin(), SCC_graph[i].in.end()), SCC_graph[i].in.end());
    }

    // for (int i = 0; i < SCC.size(); i++)
    // {
    //     cout << i;

    //     cout << "\nOUT ";
    //     for (int j = 0; j < SCC_graph[i].out.size(); j++)
    //         cout << SCC_graph[i].out[j] << " ";
    //     cout << "\nIN ";
    //     for (int j = 0; j < SCC_graph[i].in.size(); j++)
    //         cout << SCC_graph[i].in[j] << " ";
    //     cout << "\n";
    // }
}

void go_forward(int x)
{
    visited[x] = 1;
    for (int i = 0; i < SCC_graph[x].out.size(); i++)
        if (!visited[SCC_graph[x].out[i]])
            go_forward(SCC_graph[x].out[i]);
}

void go_behind(int x)
{
    visited[x] = 1;
    for (int i = 0; i < SCC_graph[x].in.size(); i++)
        if (!visited[SCC_graph[x].in[i]])
        {
            go_behind(SCC_graph[x].in[i]);
            break;
        }

    for (int i = 0; i < SCC_graph[x].out.size(); i++)
        if (!visited[SCC_graph[x].out[i]])
            go_forward(SCC_graph[x].out[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int k, l;
        cin >> k >> l;
        a[k].push_back(l);
    }

    for (int i = 1; i <= v; i++)
        if (d[i] == 0)
            dfs(i);

    for (int i = 0; i < SCC.size(); i++)
        sort(SCC[i].begin(), SCC[i].end());

    sort(SCC.begin(), SCC.end(), cmp);

    for (int i = 0; i < SCC.size(); i++)
        for (int j = 0; j < SCC[i].size(); j++)
            SCC_num[SCC[i][j]] = i;

    make_graph();

    int ans = 0;

    for (int i = 0; i < SCC.size(); i++)
    {
        if (visited[i])
            continue;

        ans++;

        go_forward(i);
        go_behind(i);
    }

    cout << ans;
}