#include <bits/stdc++.h>
#define MAX_WORKMAN 1001
#define MAX_WORK 1001

using namespace std;

int n, m;
vector<int> processables[MAX_WORKMAN];
int bToa[MAX_WORK];
int visited[MAX_WORK];

// 직원 집합의 a 원소에서 해야할 일에 매칭 가능한지..
bool dfs(int a)
{
    for (int i = 0; i < processables[a].size(); i++) {
        int t = processables[a][i];
        
        if (visited[t])
            continue;
        visited[t] = 1;

        if (bToa[t] == -1 || dfs(bToa[t])) {
            bToa[t] = a;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k; // i번 직원이 처리할 수 있는 일의 개수
        for (int j = 0; j < k; j++)
        {
            int work;
            cin >> work;
            processables[i].push_back(work);
        }
    }

    memset(bToa, -1, sizeof(bToa));
    memset(visited, 0, sizeof(visited));

    int sol = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
        {
            sol++;
        }
    }
    cout << sol;
}
