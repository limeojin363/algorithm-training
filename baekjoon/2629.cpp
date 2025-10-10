#include <iostream>
#include <vector>

using namespace std;

int n, m;
int pendulum[30];
int bead[7];
int dp[40001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pendulum[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> bead[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        // for (int i = 0; i < 6; i++)
        //     cout << dp[i] << " ";

        int k = pendulum[i];
        vector<int> to_check;

        for (int j = 0; j <= 40000; j++)
        {
            if (dp[j] == 1)
            {
                if (abs(j - k) <= 40000)
                    to_check.push_back(abs(j - k));
                if (abs(j + k) <= 40000)
                    to_check.push_back(abs(j + k));
            }
        }

        for (int j = 0; j < to_check.size(); j++)
            dp[to_check[j]] = 1;
    }

    for (int i = 0; i < m; i++)
        cout << (dp[bead[i]] ? "Y " : "N ");
}