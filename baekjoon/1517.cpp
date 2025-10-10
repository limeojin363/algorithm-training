#include <iostream>

typedef long long ll;

using namespace std;

ll init(int start, int end, int idx);
ll swap_count(int start, int end, int idx, int left, int right);

int n;
ll v[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
}