#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<long int> output;
    for(int i=0;i<n;i++)
    {
        long int t=((a[i]-i)/n);
        //cout<<a[i]-i<<" "<<a[i]<<" "<<i<<" "<<t<<endl;
        if((a[i]-i)<0)
        {
            t=0;
        }
        else if((a[i]-i)%n!=0)
            t++;
        output.push_back(t);
    }
    // for(int i=0;i<output.size();i++)
    // {
    //     cout<<output[i]<<" ";
    // }
    cout<<endl;
    int min_index=min_element(output.begin(),output.end())-output.begin();
    cout<<min_index+1;
	return 0;
}
