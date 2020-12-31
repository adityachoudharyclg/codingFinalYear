#include <bits/stdc++.h>
using namespace std;
class List;
class Node {
    int data;
    Node* next;

   public:
    friend class List;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    int getData() {
        return data;
    }
    void setData(int data) {
        this->data = data;
    }
    Node* getNext() {
        return this->next;
    }
};
class List {
    Node *head, *rear;
    int size;

   public:
    List() {
        head = NULL;
        rear = NULL;
        size = 0;
    }
    List(int data) {
        head = new Node(data);
        rear = head;
        size = 1;
    }
    void insertAtFront(int data) {
        if (size == 0) {
            head = new Node(data);
            rear = head;
            size = 1;
        } else {
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            size++;
        }
    }
    void insertAtEnd(int data) {
        if (size == 0) {
            head = new Node(data);
            rear = head;
            size = 1;
        } else {
            Node* temp = new Node(data);
            rear->next = temp;
            rear = temp;
            size++;
        }
    }
    int deleteAtFront() {
        if (size == 0) {
            return -1;
        } else {
            Node* temp = head;
            head = head->next;
            int data = temp->data;
            delete temp;
            size--;
            return data;
        }
    }
    int deleteAtEnd() {
        if (size == 0) {
            return -1;
        } else {
            Node* temp = head;
            while (temp->next != rear) {
                temp = temp->next;
            }
            temp->next = NULL;
            int data = rear->data;
            delete rear;
            rear = temp;
            size--;
            return data;
        }
    }
    Node* search(int data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    int getSize() {
        return size;
    }
    friend ostream& operator<<(ostream& a, List p);
};
ostream& operator<<(ostream& a, List p) {
    if(p.getSize()==0){
        a<<"List is empty"<<endl;
        return a;
    }
    Node* temp = p.head;
    int size = p.getSize();
    while(size!=0) {
        if (temp->getNext() != NULL) {
            a << temp->getData() << "->";
        } else {
            a << temp->getData() << endl;
        }
        temp=temp->getNext();
        size--;
    }
    return a;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    List p;
    cout << "1: Insert At Front" << endl;
    cout << "2: Insert At End" << endl;
    cout << "3: Delete At Front" << endl;
    cout << "4: Delete At End" << endl;
    cout << "5: Search X" << endl;
    cout << "6: Print List" << endl;
    while (true) {
        int choice,data;
        Node* temp;
        cout << "Enter Your Choice(1-6):";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>data;
                p.insertAtFront(data);
                break;
            case 2:
                cin>>data;
                p.insertAtEnd(data);
                break;
            case 3:
                cout<<p.deleteAtFront();
                break;
            case 4:
                cout<<p.deleteAtEnd();
                break;
            case 5:
                cin>>data;
                temp=p.search(data);
                if(temp){
                    cout<<temp->getData();
                } else {
                    cout<<"Not In List";
                }
                break;
            case 6:
                cout<<p;
                break;
        }
        char ch;
        cout<<"Do you want to enter again?(y/n):";
        cin>>ch;
        if(ch=='n'){
            break;
        }
    }

    return 0;
}