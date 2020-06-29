#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 4

// returning the greatest common divisor of two number
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Finding GCD of each row and column and replacing
// with each element with maximum of GCD of row or
// column.
void replacematrix(int mat[R][C], int n, int m) {
    int rgcd[R] = {0}, cgcd[C] = {0};

    // Calculating GCD of each row and each column in
    // O(mn) and store in arrays.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rgcd[i] = gcd(rgcd[i], mat[i][j]);
            cgcd[j] = gcd(cgcd[j], mat[i][j]);
        }
    }

    // Replacing matrix element
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = max(rgcd[i], cgcd[j]);
}

// Driven Program
int main() {
    int m[R][C] =
        {
            1,
            2,
            3,
            3,
            4,
            5,
            6,
            6,
            7,
            8,
            9,
            9,
        };

    replacematrix(m, R, C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    return 0;
}