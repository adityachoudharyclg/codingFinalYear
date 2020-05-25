#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(pair<int,int> init,pair<int,int> X,pair<int,int> Y,pair<int,int> Z,int turn){
    if(init.first<0||init.second<0){
        return -1;
    }
    if(turn==0){
        int t1=solve(make_pair(init.first+X.first,init.second+X.second),X,Y,Z,1);
        int t2=solve(make_pair(init.first+Y.first,init.second+Y.second),X,Y,Z,2);
        int t3=solve(make_pair(init.first+Z.first,init.second+Z.second),X,Y,Z,3);
        cout<<"Final:"<<t1<<" "<<t2<<" "<<t3<<endl;
        return max(t1,max(t2,t3))+1;
    } else if(turn==1){
        cout<<"X "<<init.first<<" "<<init.second<<endl;
        int t2=solve(make_pair(init.first+Y.first,init.second+Y.second),X,Y,Z,2);
        int t3=solve(make_pair(init.first+Z.first,init.second+Z.second),X,Y,Z,3);
        return max(t2,t3)+1;
    } else if(turn==2){
        cout<<"Y "<<init.first<<" "<<init.second<<endl;
        int t1=solve(make_pair(init.first+X.first,init.second+X.second),X,Y,Z,1);
        int t3=solve(make_pair(init.first+Z.first,init.second+Z.second),X,Y,Z,3);
        return max(t1,t3)+1;
    } 
    //turn==3
    cout<<"Z "<<init.first<<" "<<init.second<<endl;
    int t1=solve(make_pair(init.first+X.first,init.second+X.second),X,Y,Z,1);
    int t2=solve(make_pair(init.first+Y.first,init.second+Y.second),X,Y,Z,2);
    return max(t1,t2)+1;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        pair<int,int> init,X,Y,Z;
        cin>>init.first>>init.second;
        cin>>X.first>>X.second;
        cin>>Y.first>>Y.second;
        cin>>Z.first>>Z.second;
        cout<<X.first<<" "<<X.second<<endl;
        cout<<Y.first<<" "<<Y.second<<endl;
        cout<<Z.first<<" "<<Z.second<<endl;
        cout<<solve(init,X,Y,Z,0)<<endl;
    }
    return 0;
}