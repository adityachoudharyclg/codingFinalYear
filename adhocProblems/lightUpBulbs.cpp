#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    long long int count_zero=0,count_one=0;
    for(int i=0;i<n;)
    {
        int flag=0;
        while(s[i]=='0'&&i<n)
        {
            flag=1;
            i++;
        }
        if(flag)
            count_zero++;
        i++;
    }
    for(int i=0;i<n;)
    {
        int flag=0;
        while(s[i]=='1'&&i<n)
        {
            flag=1;
            i++;
        }
        if(flag)
            count_one++;
        i++;
    }
    if(s[0]=='1')
        count_one--;
    if(s[n-1]=='1'&&(n-1)!=0)
        count_one--;
    if(count_zero==0)
        cout<<0;
    else if(count_one==0)
        cout<<y;
    else
        cout<<min(count_one*x+y,count_zero*y);
	return 0;
}
