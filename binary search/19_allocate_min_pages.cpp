#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
// my approach
bool checkAllocate(ll arr[], ll n, ll maxBooks, ll k) {
    ll cnt = 0;
    ll i = n - 1;
    ll cur_sum = 0;
    ll flag = -1;
    while (i >= 0) {
        if (cur_sum <= maxBooks) {
            cur_sum += arr[i];
            if (cur_sum > maxBooks) {
                if (flag != i) {
                    flag = i;
                } else {
                    return false;
                }
                cnt++;
                cur_sum = 0;
            } else {
                i--;
            }
        }
    }
    if (cur_sum > 0) {
        cnt++;
    }
    // cout << k << " " << cnt << " " << cur_sum << " " << maxBooks << endl;
    return cnt <= k ? true : false;
}
// geeksforgeeks approach
bool isPossible(ll arr[], ll n, ll curr_min, ll m) {
    ll studentsRequired = 1;
    ll curr_sum = 0;

    for (ll i = 0; i < n; i++) {
        // check if current number of pages are greater
        // than curr_min that means we will get the result
        // after mid no. of pages
        if (arr[i] > curr_min)
            return false;

        // count how many students are required
        // to distribute curr_min pages
        if (curr_sum + arr[i] > curr_min) {
            // increment student count
            studentsRequired++;

            // update curr_sum
            curr_sum = arr[i];

            // if students required becomes greater
            // than given no. of students,return false
            if (studentsRequired > m)
                return false;
        }

        // else update curr_sum
        else
            curr_sum += arr[i];
    }
    return true;
}

ll solve(ll arr[], ll n, ll k) {
    // sort(arr, arr + n);
    ll start = 0;
    ll end = accumulate(arr, arr + n, 0 * 1LL);
    if (k > n) {
        return -1;
    }
    ll res = -1;
    // cout << end << endl;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        // cout << mid << endl;
        if (isPossible(arr, n, mid, k)) {
            // cout<<"hello"<<endl;
            res = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ll k;
        cin >> k;
        cout << solve(arr, n, k) << endl;
    }
    return 0;
}