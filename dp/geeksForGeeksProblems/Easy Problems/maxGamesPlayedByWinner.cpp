#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int N){
    int dp[N]; 
  
    // for 0 games, 1 player is needed 
    // for 1 game, 2 players are required 
    dp[0] = 1;     
    dp[1] = 2; 
      
    // loop until i-th Fibonacci number is   
    // less than or equal to N 
    int i = 2; 
    do { 
        dp[i] = dp[i - 1] + dp[i - 2]; 
    } while (dp[i++] <= N); 
  
    // result is (i - 2) because i will be  
    // incremented one extra in while loop 
    // and we want the last value which is  
    // smaller than N, so one more decrement 
    return (i - 2); 
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;        
    }
    return 0;
}