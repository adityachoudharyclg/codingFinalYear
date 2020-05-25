#include <bits/stdc++.h>
#define ll long long
using namespace std;
class worker {
   public:
    long long int time;
    long long int cost;
    long long int tiles;
};
bool comparator(worker a,worker b){
    if(a.time==b.time){
        if(a.tiles==b.tiles){
            return a.cost<b.cost;
        }
        return a.tiles>b.tiles;
    }
    return a.time<b.time;
}
int main() {
    //Write your code here
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    long long int n, d;
    cin >> n >> d;
    worker workers[n];
    for (long long int i = 0; i < n; i++) {
        cin >> workers[i].time >> workers[i].cost >> workers[i].tiles;
    }
    sort(workers,workers+n,comparator);
    int bestSpeed=0,lastTime=workers[0].time,cost=0;
    for(int i=0;i<n;i++){
        ll additional=bestSpeed*(workers[i].time-lastTime);
        if(additional>=d)
            break;
        else
            d-=additional;
        if(workers[i].tiles>bestSpeed){
            cost+=workers[i].cost;
            bestSpeed=workers[i].tiles;
        }
        lastTime=workers[i].time;
    }
    cout<<cost;
    return 0;
}