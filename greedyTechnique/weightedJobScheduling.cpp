#include<bits/stdc++.h>
using namespace std;
class job
{
    public:
    int start;
    int finish;
    int profit;
};
bool compare(job a,job b)
{
    return a.finish<b.finish;
}
int main()
{
    //Write your code here
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    job arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    sort(arr,arr+n,compare);
    int ans[n];
    ans[0]=arr[0].profit;
    for(int i=1;i<n;i++)
    {
        int exc=ans[i-1];
        int inc=0;
        int start=0,end=i-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid].finish<=arr[i].start)
            {
                inc=ans[mid];
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        ans[i]=max(inc+arr[i].profit,exc);
    }
    cout<<ans[n-1]<<endl;
    return 0;
}