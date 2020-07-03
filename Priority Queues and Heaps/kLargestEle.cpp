#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[],int n,int k){
    priority_queue<int,vector<int>> pq(arr,arr+n);
    while(k>0){
        cout<<pq.top()<<" ";
        pq.pop();
        k--;
    }
    cout<<endl;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        solve(arr,n,k);        
    }
    return 0;
}