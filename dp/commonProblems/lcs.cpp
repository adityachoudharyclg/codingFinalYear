#include <bits/stdc++.h>
#define ll long long
using namespace std;
void printDP(int dp[][100],int m,int n){
    cout << m << " " << n << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int dp[100][100] = {0};
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j]=1+dp[i-1][j-1];
            } else{
                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
string constructLCS(string s1,string s2){
    int m = s1.size(), n = s2.size();
    int dp[100][100] = {0};
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j]=1+dp[i-1][j-1];
            } else{
                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    char result[dp[m][n]+1];
    int i=m,j=n,len=0;
    while(i>=0&&j>=0&&len<dp[m][n]){
        if(s1[i-1]==s2[j-1]){
            result[len]=s1[i-1];
            i--;
            j--;
            len++;
        } else{
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    result[len]='\0';
    string ans(result,len);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        string s1, s2;
        cin >> s1;
        cin >> s2;
        cout << lcs(s1, s2) << endl;
        cout<<constructLCS(s1,s2)<<endl;
    }
    return 0;
}