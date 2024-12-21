// Resource: https://twpower.github.io/90-combination-by-using-next_permutation

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> n;

    // 1부터 6까지 생성
    for (int i = 0; i < 6; i++)
        n.push_back(i + 1);

    vector<int> ind;

    int k = 4;
    for (int i = 0; i < k; i++)
        ind.push_back(1);

    for (int i = 0; i < n.size() - k; i++)
        ind.push_back(0);
    sort(ind.begin(), ind.end());

    do
    {
        for (int i = 0; i < ind.size(); i++)
            if (ind[i] == 1)
                printf("%d ", i);

        printf("\n");

    } while (next_permutation(ind.begin(), ind.end()));

    return 0;
}
