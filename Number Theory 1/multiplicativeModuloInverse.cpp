#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class triplet{
    public:
    int x,y,gcd;
} ;
triplet gcd(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=gcd(b,a%b);
    triplet ans;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    ans.gcd=smallAns.gcd;
    return ans;
}
void solve(int a,int m){
    if(__gcd(a,m)==1){
        triplet ans=gcd(a,m);
        cout<<"B is:"<<ans.x<<endl;
        return;
    }
    cout<<"B doesnt exists"<<endl;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int a,m;
        cin>>a>>m;
        solve(a,m);
    }
    return 0;
}