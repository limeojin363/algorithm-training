#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, capacity;
int customer[50001];
int customerSum[50001];
int cache[50001][3];

int dp(int idx, int used);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> customer[i];
    cin >> capacity;

    customerSum[0] = customer[0];
    for (int i = 1; i < n; i++)
        customerSum[i] = customerSum[i - 1] + customer[i];

    // for (int i = 0; i < n; i++)
    //     cout << customerSum[i] << " ";
    // cout << "\n";

    memset(cache, -1, sizeof(cache));

    cout << dp(0, 0);
}

int dp(int idx, int used)
{
    if (used == 3)
        return 0;

    if (idx >= n)
        return 0;

    int &ret = cache[idx][used];
    if (ret != -1)
        return ret;

    int selectedCustomerSum;
    if (idx == 0)
        selectedCustomerSum = customerSum[capacity - 1]; // 0 ~ capacity - 1
    else if (idx + capacity >= n)
        selectedCustomerSum = customerSum[n - 1] - customerSum[idx - 1];
    else
        selectedCustomerSum = customerSum[idx + capacity - 1] - customerSum[idx - 1]; // idx ~ idx + capacity - 1

    return ret = max(dp(idx + 1, used), selectedCustomerSum + dp(idx + capacity, used + 1));
}