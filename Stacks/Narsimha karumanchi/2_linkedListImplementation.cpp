#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class Stack{
    Node* head;
    int size;
    public:
    Stack(){
        head=NULL;
        size=0;
    }
    void push(int data){
        if(size==0){
            head=new Node(data);
            size++;
            return;
        }
        Node* temp=new Node(data);
        temp->next=head;
        head=temp;
        size++;
    }
    int pop(){
        if(head==NULL){
            return -1;
        }
        int topData=head->data;
        head=head->next;
        size--;
        return topData;
    }
    int top(){
        return head->data;
    }
    int stkSize(){
        return size;
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    Stack stk;
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
            cout<<stk.stkSize()<<endl;
        }
    }
    return 0;
}