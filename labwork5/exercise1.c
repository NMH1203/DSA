#include <stdio.h>
#include <stdlib.h>

void flip(int a[], int i)
{
    int t, s = 0;                       
    while (s < i) {                     
        t = a[s];                       
        a[s] = a[i];
        a[i] = t;
        s++;
        i--;
    }
}
// -> complecity: O(n)
int findMax(int a[], int n)
{
    int m, i;
    for (m = 0, i = 0; i < n; ++i)
        if (a[i] > a[m])
            m = i;
    return m;
}
// -> complexity: O(n)

void sort(int* a, int n)
{
    for (int i = n; i > 1;--i)      //n
    {
        int m = findMax(a, i);      //n
        if (m != i - 1) {       
            flip(a, m);             //n
            flip(a, i - 1);         //n
        }
    }
}
// n*(n+n+n))
// 3n^2
// -> complexity: O(n^2)
void print(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
}

int main()
{
    int arr[] = { 34, 50, 10, 11, 15, 7, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);
    print(arr, n);

    return 0;
}