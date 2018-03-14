//BNPCHS2010I - Misteri Rekursi Fibonacci
//BNPCHS 2010 - Problem I
//Tag : Simple Dynamic-Programming 

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (m == 0 && n == 1 || m > n) {
            cout << "0\n";
            continue;
        }
        if (m == 0) n -= 2;
        else n -= m;
        if (n < 2) {
            cout << "1\n";
            continue;
        }
        int n0, n1, val;
        n0 = n1 = 1;
        for (int i = 0; i < n-1; i++) {
            val = n0 + n1;
            //cout << n0 << "+" << n1 << "=" << val <<endl;
            n0 = n1 % 10000;
            n1 = val % 10000;
            val %= 10000;
        }
        cout << val % 10000 << "\n";
    }
    return 0;
}
