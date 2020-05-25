#include<bits/stdc++.h>
using namespace std;
void print(int dp[],int n){
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}
int solve(vector<int> price){
    int dp[4001]={0};
    for(int i=1;i<=price.size();i++){
        int ans=INT_MIN;
        for(int j=1;j<=i;j++){
            if(ans<(price[j-1]+dp[i-j]))
                ans=price[j-1]+dp[i-j];
        }
        dp[i]=ans;
    }
    return dp[price.size()];
}
void construct(vector<int> price){
    int dp[4001]={0};
    int s[4001]={0};
    for(int i=1;i<=price.size();i++){
        int ans=INT_MIN;
        for(int j=1;j<=i;j++){
            if(ans<(price[j-1]+dp[i-j])){
                ans=price[j-1]+dp[i-j];
                s[i]=j;
            }
        }
        dp[i]=ans;
    }
    int n=price.size();
    while(n>0){
        cout<<s[n]<<" ";
        n-=s[n];
    }
    cout<<endl;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        int num;
        cin>>num;
        for(int i=0;i<num;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        cout<<solve(v)<<endl;
        construct(v);
    }
}