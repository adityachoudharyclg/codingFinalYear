#include<bits/stdc++.h>
using namespace std;
bool check(char arr[][10],int i,int j,int n){
    // bool flag1=true,flag2=true;
    for(int k=i;k>=0;k--){
        if(arr[k][j]=='1'){
            return false;
        }
    }
    for(int k=i,l=j;k>=0&&l>=0;k--,l--){
        if(arr[k][l]=='1'){
            return false;
        }
    }
    for(int k=i,l=j;k>=0&&l<n;k--,l++){
        if(arr[k][l]=='1'){
            return false;
        }
    }
    return true;
}
void nqueenSolver(char arr[][10],int i,int n){
    if(i==n){
        // cout<<"hello"<<endl;
        for(int i=0;i<n;i++){
            for (int j = 0; j < n; j++){
                cout<<arr[i][j]<<" ";
            }
            // cout<<endl;
        }
        cout<<endl;
        return ;
    }
    for(int j=0;j<n;j++){
        if(check(arr,i,j,n)){
            arr[i][j]='1';
            nqueenSolver(arr,i+1,n);
        }
        arr[i][j]='0';
    }
}
void placeNQueens(int n){
    char arr[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            arr[i][j]='0';
    }
    nqueenSolver(arr,0,n);
}
int main(){
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}