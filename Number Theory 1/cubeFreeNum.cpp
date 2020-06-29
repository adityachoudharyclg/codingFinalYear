#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int* cubeFree=new int[1000001]();
void computeCubeFree(){
    for(int i=0;i<=1000000;i++){
        cubeFree[i]=0;
    }
    for(int i=2;i*i*i<=1000000;i++){
        for(int j=i*i*i;j<=1000000;j+=i*i*i){
            cubeFree[j]=-1;
        }
    }
    int k=0;
    for(int i=1;i<=1000000;i++){
        k+=cubeFree[i];
        k++;
        if(cubeFree[i]!=-1){
            cubeFree[i]=k;
        }
        // cout<<cubeFree[i]<<endl;
    }
}
void solve(int n,int k){
    if(cubeFree[n]!=-1){
        cout<<"Case "<<k<<": "<<cubeFree[n]<<endl;
    } else {
        cout<<"Case "<<k<<": "<<"Not Cube Free"<<endl;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    int k=0;
    computeCubeFree();
    while(k<t){
        int n;
        cin>>n;
        solve(n,k+1);
        k++;
    }
    return 0;
}