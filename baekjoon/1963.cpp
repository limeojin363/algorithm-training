// 자릿수 추출 실수하지 마라

#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int isPrime[10001];
int visited[10001];

void primeNumberSieve()
{
    for (int i = 2; i <= 9999; i++)
        isPrime[i] = i;

    for (int i = 2; i <= sqrt(9999); i++)
    {
        if (isPrime[i] == 0)
            continue;

        for (int j = i * i; j <= 9999; j += i)
            isPrime[j] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    primeNumberSieve();

    int t;
    cin >> t;
    while (t--)
    {
        int start1, end1;
        cin >> start1 >> end1;

        memset(visited, -1, sizeof(visited));

        queue<int> q = {};

        q.push(start1);
        visited[start1] = 0;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            int thousand = x / 1000;
            int hundred = x % 1000 / 100;
            int ten = x % 100 / 10;
            int one = x % 10 / 1;

            vector<int> v = {};
            for (int i = 0; i <= 9; i++)
            {
                v.push_back(i * 1000 + hundred * 100 + ten * 10 + one * 1);
                v.push_back(thousand * 1000 + i * 100 + ten * 10 + one * 1);
                v.push_back(thousand * 1000 + hundred * 100 + i * 10 + one * 1);
                v.push_back(thousand * 1000 + hundred * 100 + ten * 10 + i * 1);
            }

            for (int i = 0; i < v.size(); i++)
            {
                if ((v[i] == x) || (v[i] < 1000) || (visited[v[i]] != -1) || (isPrime[v[i]] == 0))
                    continue;

                visited[v[i]] = visited[x] + 1;
                q.push(v[i]);
            }
        }

        if (visited[end1] == -1)
            cout << "Impossible\n";
        else
            cout << visited[end1] << "\n";
    }
}