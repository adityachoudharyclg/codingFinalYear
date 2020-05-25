#include<bits/stdc++.h>
using namespace std;
bool check(int arr[],int n,int chocolates,int k){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i]/chocolates;
    }
    return sum>=k?true:false;
}
int solution(int arr[],int n,int k){
    int start=1,end=1000000000;
    int mid;
    int ans=-1;
    while(start<=end){
        mid=start+(end-start)/2;
        if(check(arr,n,mid,k)){
            start=mid+1;
            ans=mid;
        } else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solution(arr,n,k)<<endl;
    }
    return 0;
}