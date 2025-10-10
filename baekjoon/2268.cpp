// https://www.acmicpc.net/problem/2042

#include <bits/stdc++.h>

using namespace std;

long long init(int start, int end, int idx);
long long interval_sum(int start, int end, int idx, int left, int right);
void update(int start, int end, int idx, int what, long long value);

int n, m;
long long v[1000001];
long long seg_tree[4000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    init(0, n - 1, 1);

    for (int i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(0, n - 1, 1, b - 1, c - v[b - 1]);
            v[b - 1] = c; // 이거 안해주면 오버플로우남
        }
        else if (a == 0)
        {
            if (b > c)
            {
                long long temp = b;
                b = c;
                c = temp;
            }
            cout << interval_sum(0, n - 1, 1, b - 1, c - 1) << "\n";
        }
    }
}

long long init(int start, int end, int idx)
{
    if (start == end)
        return (seg_tree[idx] = v[start]);

    int mid = (start + end) / 2;

    return (seg_tree[idx] = init(start, mid, 2 * idx) + init(mid + 1, end, 2 * idx + 1));
}

long long interval_sum(int start, int end, int idx, int left, int right)
{
    if (left > end || right < start)
        return 0;

    if (left <= start && right >= end)
        return seg_tree[idx];

    int mid = (start + end) / 2;

    return (interval_sum(start, mid, idx * 2, left, right) + interval_sum(mid + 1, end, idx * 2 + 1, left, right));
}

void update(int start, int end, int idx, int what, long long value)
{
    if (what < start || what > end)
        return;

    seg_tree[idx] += value;
    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(start, mid, idx * 2, what, value);
    update(mid + 1, end, idx * 2 + 1, what, value);
}