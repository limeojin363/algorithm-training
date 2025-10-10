#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int dp(int x);

int n;
int arr[17][17]; // arr[i][j]: i -> j 재시작
int cache[(2 << 17) - 1];
int p;
int start = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
        if (str[i] == 'Y')
            start += pow(2, i);

    cin >> p;

    memset(cache, -1, sizeof(cache));
    cout << (dp(start) == 36 * 16 ? -1 : dp(start));
}

int dp(int x)
{
    int &ret = cache[x];
    if (ret != -1)
        return ret;

    ret = 36 * 16;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (x & (1 << i)) // i번째 발전소가 가동중이라면 cnt에 1을 더함
            cnt++;

    if (cnt >= p)
        return ret = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((x & (1 << j)) && !(x & (1 << i))) // j번째 발전소가 가동 중 -> j로 i를 고칠 수 있음
                ret = min(ret, dp(x | (1 << i)) + arr[j][i]);

    return ret;
}