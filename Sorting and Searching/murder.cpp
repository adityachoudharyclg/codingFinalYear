#include <bits/stdc++.h>
using namespace std;

long long merge(int A[], int left, int mid, int right)
{
    int i = left, j = mid, k = 0;
    int temp[right - left + 1];
    long long sum = 0;
    while (i < mid && j <= right)
    {
        if (A[i] < A[j])
        {
            sum = sum + (right - j + 1) * A[i];
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
        }
    }
    while (i < mid)
    {
        temp[k++] = A[i++];
    }
    while (j <= right)
        temp[k++] = A[j++];
    for (int i = left, k = 0; i <= right; i++, k++)
    {
        A[i] = temp[k];
    }
    return sum;
}
long long merge_sort(int A[], int left, int right)
{
    long long ans = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        long long ans1 = merge_sort(A, left, mid);
        long long ans2 = merge_sort(A, mid + 1, right);
        long long ans3 = merge(A, left, mid + 1, right);
        return ans1 + ans2 + ans3;
    }
    return ans;
}
long long solve(int A[], int n)
{
    // Write your code here.
    long long ans = merge_sort(A, 0, n - 1);
    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << solve(A, n);
        cout << endl;
    }
}