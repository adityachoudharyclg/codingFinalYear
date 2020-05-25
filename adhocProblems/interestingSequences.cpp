#include<bits/stdc++.h>
using namespace std;
int calcCost(int *arr,int n,int pivot,int k,int l)
{
    int inc=0,dec=0;
    //cout<<pivot<<endl;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<pivot)
            inc+=(pivot-arr[i]);
        else if(arr[i]>pivot)
            dec+=(arr[i]-pivot);
    }
    //cout<<inc<<" "<<dec<<endl;
    if(inc<dec)
        return INT_MAX;
    else
        return dec*k+(inc-dec)*l;
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    int arr[n];
    int k,l;
    cin>>k>>l;
    int minCost=INT_MAX;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int mini=*min_element(arr,arr+n);
    int maxi=*max_element(arr,arr+n);
    for(int i=mini;i<=maxi;i++)
    {
        int t=calcCost(arr,n,i,k,l);
        if(minCost>t)
            minCost=t;
    }
    cout<<minCost;
    return 0;
}