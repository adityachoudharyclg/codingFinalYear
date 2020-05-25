#include<bits/stdc++.h>
using namespace std;
int merge(vector<int> leftArr,vector<int> rightArr,vector<int> &arr){
    int i=0,j=0,k=0;
    int count=0;
    while(i<leftArr.size()&&j<rightArr.size()){
        if(leftArr[i]<=rightArr[j]){
            arr[k++]=leftArr[i++];
        } else{
            arr[k++]=rightArr[j++];
            count+=(leftArr.size()-i);
        }
    }
    while(i<leftArr.size()){
        arr[k++]=leftArr[i++];
    }
    while (j<rightArr.size()){
        arr[k++]=rightArr[j++];
        count+=(leftArr.size()-i);
    }
    // cout<<"Hello"<<" "<<count;
    return count;
}
int mergeSort(vector<int> &arr){
    if(arr.size()<=1){
        return 0;
    }
    int mid=arr.size()/2;
    vector<int> leftArr,rightArr;
    for(int i=0;i<arr.size();i++){
        if(i<mid){
            leftArr.push_back(arr[i]);
        } else{
            rightArr.push_back(arr[i]);
        }
    }
    // cout<<mid<<" "<<arr.size()<<" "<<leftArr.size()<<" "<<rightArr.size()<<endl;
    int left=mergeSort(leftArr);
    int right=mergeSort(rightArr);
    int count=merge(leftArr,rightArr,arr);
    return left+count+right;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        int num;
        cin>>num;
        for(int i=0;i<num;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        // cout<<v.size();
        cout<<mergeSort(v);
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
    }
}