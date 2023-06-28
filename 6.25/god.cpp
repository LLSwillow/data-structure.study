#include <iostream>
using namespace std;
const int N = 1e5 + 10; // 范围怎么看呀？
int n, q;
int a[N];
long long s[N];
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    while (q--)
    {
        int f, t;
        cin >> f >> t;
        cout << s[t] - s[f - 1] << endl;
    }
    return 0;
}