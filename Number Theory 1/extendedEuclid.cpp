#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Triplet{
    public:
    int x,y,gcd;
};
Triplet solve(int a,int b){
    if(b==0){
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    Triplet smallAns=solve(b,a%b);
    Triplet ans;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    ans.gcd=smallAns.gcd;
    return ans;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        Triplet ans=solve(a,b);
        cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
    }
    return 0;
}