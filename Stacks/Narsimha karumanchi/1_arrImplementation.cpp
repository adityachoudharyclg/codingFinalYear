#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Stack {
    int* arr;
    int size;
    int topIndex;

   public:
    Stack(int n) {
        arr = new int[n];
        size = n;
        topIndex = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int num);
    int pop();
    int top();
    int capacity();
};
void Stack::push(int num) {
    if (topIndex == size - 1) {
        cout << "overflow" << endl;
        return;
    }
    arr[++topIndex] = num;
}
int Stack::pop() {
    if (topIndex == -1) {
        cout << "Underflow" << endl;
        return -1;
    }
    int temp = arr[topIndex];
    topIndex--;
    return temp;
}
int Stack::top() {
    return arr[topIndex];
}
int Stack::capacity() {
    return size;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    Stack stk(5);
    while (t--) {
        int q;
        cin>>q;
        if(q==0){
            int x;
            cin>>x;
            stk.push(x);
        } else if(q==1){
            cout<<stk.pop()<<endl;
        } else if(q==2){
            cout<<stk.top()<<endl;
        } else if(q==3){
            cout<<stk.capacity()<<endl;
        }
    }
    return 0;
}