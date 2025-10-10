#include <bits/stdc++.h>

using namespace std;

long long init(int start, int end, int idx);
long long interval_product(int start, int end, int idx, int left, int right);
void update(int start, int end, int idx, int what, long long value);

int n, m, k;
long long v[1000001];
long long seg_tree[4000001];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    init(0, n - 1, 1);

    for (int i = 0; i < m + k; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1)
            update(0, n - 1, 1, b - 1, c);
        else if (a == 2)
            cout << (interval_product(0, n - 1, 1, b - 1, c - 1) % 1000000007) << "\n";
    }
}

long long init(int start, int end, int idx)
{
    if (start == end)
        return (seg_tree[idx] = v[start]);

    int mid = (start + end) / 2;

    return seg_tree[idx] = (init(start, mid, 2 * idx) * init(mid + 1, end, 2 * idx + 1)) % 1000000007;
}

long long interval_product(int start, int end, int idx, int left, int right)
{
    if (left > end || right < start)
        return 1;

    if (left <= start && right >= end)
        return seg_tree[idx];

    int mid = (start + end) / 2;

    return (interval_product(start, mid, idx * 2, left, right) * interval_product(mid + 1, end, idx * 2 + 1, left, right)) % 1000000007;
}

void update(int start, int end, int idx, int what, long long value)
{
    if (what < start || what > end)
        return;

    if (start == end)
        seg_tree[idx] = value;
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, idx * 2, what, value);
        update(mid + 1, end, idx * 2 + 1, what, value);

        seg_tree[idx] = seg_tree[idx * 2] * seg_tree[idx * 2 + 1] % 1000000007;
    }
}