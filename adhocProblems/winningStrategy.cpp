#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ts=0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==i+1)
        {
            continue;
        }
        else if((i-1)>=0&&arr[i-1]==i+1)
        {
            swap(arr[i-1],arr[i]);
            ts++;
        }
        else if((i-2)>=0&&arr[i-2]==i+1)
        {
            swap(arr[i-2],arr[i-1]);
            swap(arr[i-1],arr[i]);
            ts+=2;
        }
        else
        {
            cout<<"NO";
            return 0;
        }
            
    }
    cout<<"YES"<<endl;
    cout<<ts<<endl;
    return 0;
}