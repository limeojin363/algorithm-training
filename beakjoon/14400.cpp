#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long customerX[100000];
long long customerY[100000];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> customerX[i] >> customerY[i];

  sort(customerX, customerX + n);
  sort(customerY, customerY + n);

  long long x = customerX[n / 2];
  long long y = customerY[n / 2];
  
  long long res = 0;
  for (int i = 0; i < n; i++)
    res += (abs(x - customerX[i]) + abs(y - customerY[i]));

  cout << res;
}