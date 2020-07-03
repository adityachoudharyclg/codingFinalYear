#include <bits/stdc++.h>
using namespace std;
class mergeK {
   public:
    int data;
    int arr_index;
    int ele_index;
};

struct compare {
    bool operator()(mergeK const& p1, mergeK const& p2) {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.data > p2.data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<mergeK, vector<mergeK>, compare> pq;
    vector<int> res;
    for (int i = 0; i < input.size(); i++) {
        vector<int> v = *input[i];
        mergeK a;
        a.arr_index = i;
        a.ele_index = 0;
        a.data = v[0];
        pq.push(a);
    }
    int k = 0;
    while (k < input.size()) {
        mergeK a = pq.top();
        pq.pop();
        res.push_back(a.data);
        a.ele_index++;
        vector<int> v = *input[a.arr_index];
        if (v.size() == a.ele_index)
            k++;
        else {
            a.data = v[a.ele_index];
            pq.push(a);
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    cin >> k;
    vector<vector<int>*> input;
    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int>* current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }
        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    return 0;
}
