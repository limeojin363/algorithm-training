#include <iostream>
#include <cstring>

using namespace std;

int dp(int left, int right);

int n;
int card[10001];
int partialSum[10001];
int cache[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> card[j];

        partialSum[0] = card[0];
        for (int j = 1; j < n; j++)
            partialSum[j] = partialSum[j - 1] + card[j];

        memset(cache, -1, sizeof(cache));

        cout << dp(0, n - 1) << "\n";
    }
}

// left + right가 짝수 -> 근우
// left + right가 홀수 -> 명우
int dp(int left, int right)
{
    int &ret = cache[left][right];
    if (ret != -1)
        return ret;

    if (left == right)
        return ret = card[left];

    // 왼쪽을 고른 케이스
    int leftSel = 0;
    // 왼쪽 카드 값 더하기
    leftSel += card[left];
    // 상대의 상황: left는 += 1, right는 그대로
    // (상대의 상황에서) 전체 카드 합에서 얻을 수 있는 optimal한 값을 빼면 그게 곧 내가 얻는 값
    leftSel += ((partialSum[right] -
                 (left + 1 == 0 ? 0 : partialSum[left + 1 - 1])) -
                dp(left + 1, right));

    // 오른쪽을 고른 케이스
    int rightSel = 0;
    // 오른쪽 카드 값 더하기
    rightSel += card[right];
    // 상대의 상황: left는 그대로, right는 -=1
    // (상대의 상황에서) 전체 카드 합에서 얻을 수 있는 optimal한 값을 빼면 그게 곧 내가 얻는 값
    rightSel += ((partialSum[right - 1] -
                  (left == 0 ? 0 : partialSum[left - 1])) -
                 dp(left, right - 1));

    cout << "leftSel: " << leftSel << " rightSel: " << rightSel << "\n";

    return ret = max(leftSel, rightSel);
}
