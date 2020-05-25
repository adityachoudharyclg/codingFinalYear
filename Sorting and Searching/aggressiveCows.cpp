#include<bits/stdc++.h>
using namespace std;
bool check(long long int arr[],int size,long long int cows,long long int d){
    long long int initial=arr[0];
    cows--;
    if(cows==0){
        return true;
    }
    for(long long int i=1;i<size;i++){
        if((arr[i]-initial)>=d){
            cows--;
            initial=arr[i];
        }
        if(cows==0){
            return true;
        }
    }
    return false;
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        long long int positions[n],start,end,ans;
        for(int i=0;i<n;i++)
            cin>>positions[i];
        sort(positions,positions+n);
        start=0;
        end=positions[n-1]-positions[0];
        ans=-1;
        while(start<=end)
        {            
            long long int mid=start+(end-start)/2;
            //cout<<start<<" "<<end<<" "<<check(positions,n,c,mid)<<endl;
            if(check(positions,n,c,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}