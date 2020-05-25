#include<bits/stdc++.h>
using namespace std;
pair<int,int> solve(int arr[],int sum,int temp[],int n,int x){
    
    // cout<<"Hello"<<sum<<endl;
    int momosPurchased=(x/sum)*n;
    int moneyLeft=x%sum;
    // cout<<momosPurchased<<" "<<moneyLeft<<endl;
    
    int start=0,end=n-1;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(moneyLeft>=temp[mid]){
            start=mid+1;
            ans=mid;
        } else{
            end=mid-1;
        }
    }
    if(ans==-1){
        return make_pair(momosPurchased,moneyLeft);
    }
    return make_pair(momosPurchased+ans+1,moneyLeft-temp[ans]);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int q;
    cin>>q;
    long long int sum=accumulate(arr,arr+n,0);
    int temp[n];
    temp[0]=arr[0];
    for(int i=1;i<n;i++){
        temp[i]=temp[i-1]+arr[i];
    }
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        pair<int,int> p=solve(arr,sum,temp,n,x);
        cout<<p.first<<" "<<p.second<<endl;
    }
}