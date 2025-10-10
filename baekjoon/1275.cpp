#include <bits/stdc++.h>

using namespace std;

long long init(int start, int end, int idx);
long long interval_sum(int start, int end, int idx, int left, int right);
void update(int start, int end, int idx, int what, long long value);

int n, q;
long long v[1000001];
long long seg_tree[4000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    init(0, n - 1, 1);

    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        long long d;
        cin >> a >> b >> c >> d;

        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        cout << interval_sum(0, n - 1, 1, a - 1, b - 1) << "\n";

        update(0, n - 1, 1, c - 1, d - v[c - 1]);
        v[c - 1] = d; // 안해주면 오버플로우남
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