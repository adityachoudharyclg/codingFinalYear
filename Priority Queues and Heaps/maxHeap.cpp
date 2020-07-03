#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void maxHeapify(int* arr, int index, int n) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;
    if (leftChild < n && arr[index] < arr[leftChild]) {
        largest = leftChild;
    }
    if (rightChild < n && arr[largest] < arr[rightChild]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(arr[largest], arr[index]);
        maxHeapify(arr, largest, n);
    }
}

void createHeap(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, n);
    }
}

void insertHeap(int* arr, int& n, int ele) {
    arr[n] = ele;
    int index = n;
    // Size changed
    n = n + 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
        } else {
            break;
        }
        index = parent;
    }
}

int deleteHeap(int* arr, int& n) {
    if (n == 0) {
        return -1;
    }
    int ans = arr[0];
    swap(arr[0], arr[n - 1]);
    n--;
    maxHeapify(arr, 0, n);
    return ans;
}

void heapSort(int* arr, int n) {
    int temp = n;
    for (int i = 0; i < temp - 1; i++) {
        deleteHeap(arr, n);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int* arr = new int[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    createHeap(arr, n);
    insertHeap(arr, n, 20);
    insertHeap(arr, n, -4);
    insertHeap(arr, n, 6);
    insertHeap(arr, n, 8);
    // cout<<deleteHeap(arr,n)<<endl;
    // cout<<deleteHeap(arr,n)<<endl;
    // cout<<deleteHeap(arr,n)<<endl;
    // cout<<deleteHeap(arr,n)<<endl;
    // cout<<deleteHeap(arr,n)<<endl;
    heapSort(arr, n);
    // Display array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}