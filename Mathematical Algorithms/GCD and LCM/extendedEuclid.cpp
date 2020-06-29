#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Ext{
    public:
    int x,y,gcd;
};
Ext helper(int a,int b){
    if(b==0){
        Ext temp;
        temp.x=1;
        temp.y=0;
        temp.gcd=a;
        return temp;
    }
    Ext temp=helper(b,a%b);
    Ext res;
    res.x=temp.y;
    res.y=temp.x-((a/b)*temp.y);
    res.gcd=temp.gcd;
    return res;
}
int solve(int a,int b){
    Ext res;
    res=helper(a,b);
    cout<<res.x<<" "<<res.y<<endl;
    return res.gcd;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}