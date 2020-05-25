#include <bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}
int activitySelection(pair<int,int> arr[],int n){
    sort(arr,arr+n,comparator);
    int count=1;
    int finishTime=arr[0].second;
    for(int i=0;i<n;i++){
        if(arr[i].first>=finishTime){
            finishTime=arr[i].second;
            count++;
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    pair<int,int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first>>arr[i].second;
    }
    cout<<activitySelection(arr,n);
    return 0;
}