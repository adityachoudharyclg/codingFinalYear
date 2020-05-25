#include <bits/stdc++.h>
using namespace std;
class Point {
   public:
    float x;
    float y;
};
float dist(Point a,Point b){
    double res=double(a.x-b.x)*(a.x-b.x)+double(a.y-b.y)*(a.y-b.y);
    return float(pow(double(res),0.5));
}
bool compareX(Point a,Point b){
    return a.x<b.x;
}
bool compareY(Point a,Point b){
    return a.y<b.y;
}
float bruteForce(vector<Point> points,int n){
    float minDist=FLT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double temp=dist(points[i],points[j]);
            if(temp<minDist){
                minDist=temp;
            }
        }
    }
    return minDist;
}

float solution(Point points[],int n){
    if(n==1){
        return FLT_MAX;
    } else if(n==2){
        return dist(points[0],points[1]);
    }
    sort(points,points+n,compareX);
    int mid=n/2;
    float dl=solution(points,n/2);
    float dr=solution(points+n/2,n-n/2);
    float d=min(dl,dr);
    // cout<<d<<endl;
    vector<Point> strip;
    for(int i=0;i<n;i++){
        if(abs(d)>=abs(points[mid].x-points[i].x)){
            strip.push_back(points[i]);
        }
    }
    sort(strip.begin(),strip.end(),compareY);
    float dStrip=bruteForce(strip,strip.size());
    return min(d,dStrip);
}
int main() {
    int n;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    cout<<solution(points,n);
    return 0;
}