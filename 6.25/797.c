#include <stdio.h>
void New(int l, int r, int c, int arr[])
{
    for (int i = l; i <= r; i++)
    {
        arr[i] += c;
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int l, r, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &l, &r, &c);
        New(l - 1, r - 1, c, arr);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}