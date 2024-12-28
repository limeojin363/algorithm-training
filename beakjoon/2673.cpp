#include <bits/stdc++.h>
#define N_MAX 50
#define MIN_POINT 1
#define MAX_POINT 100

using namespace std;

int getMaxCountInRange(int start, int end);
void preset();
void solve();

pair<int, int> lines[N_MAX];
int n;
int cache[MAX_POINT + 1][MAX_POINT + 1];

int getMaxCountInRange(int start, int end)
{
    if (start >= end)
        return 0;

    int &ret = cache[start][end];
    if (ret != -1)
        return ret;

    ret = 0;

    for (int i = 0; i < n; i++)
    {
        int selectedStart = lines[i].first;
        int selectedEnd = lines[i].second;

        if (start <= selectedStart && selectedEnd <= end)
            ret = max(ret, 1 + getMaxCountInRange(start, selectedStart - 1)
                             + getMaxCountInRange(selectedStart + 1, selectedEnd - 1)
                             + getMaxCountInRange(selectedEnd + 1, end));
    }

    return ret;
}

void preset()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].first >> lines[i].second;
        if (lines[i].first > lines[i].second)
        {
            int temp = lines[i].first;
            lines[i].first = lines[i].second;
            lines[i].second = temp;
        }
    }

    memset(cache, -1, sizeof(cache));
}

void solve()
{
    cout << getMaxCountInRange(MIN_POINT, MAX_POINT);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preset();
    solve();
}
