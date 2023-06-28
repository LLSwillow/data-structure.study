#include <iostream>
using namespace std;
const int N = 1000;
int p[N][N], q[N][N];
int T, m, n, x, y;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> m >> n >> x >> y;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> p[i][j];
                q[i][j] = q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1] + p[i][j];
            }
        }
        int max = 0;
        for (int i = x; i <= m; i++)
        {
            for (int j = y; j <= n; j++)
            {
                if (q[i][j] - q[i - x][j] - q[i][j - y] + q[i - x][j - y] > max)
                {
                    max = q[i][j] - q[i - x][j] - q[i][j - y] + q[i - x][j - y];
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}