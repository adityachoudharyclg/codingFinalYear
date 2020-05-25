#include<bits/stdc++.h>
using namespace std;
int turnOffFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int t=n&(-1*n);
    n=n^t;
    // cout<<t<<endl;
    return n;
}
int flipIthBit(int n,int i){
    int t=1<<i;
    return n^t;
}
int clearAllBitsFromLSBToI(int n,int i){
    int t=1<<(i+1);
    t=t-1;
    t=~t;
    return n&t;
}
int main(){
    int n;
    cin>>n;
    // cout<<"turnOffFirstSetBit:"<<" "<<turnOffFirstSetBit(n)<<endl;
    // cout<<"flipIthBit:"<<" "<<flipIthBit(n,1)<<endl;
    cout<<clearAllBitsFromLSBToI(n,2);
    return 0;
}