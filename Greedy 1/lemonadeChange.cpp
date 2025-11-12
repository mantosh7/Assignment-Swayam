#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int fiveDollar = 0, tenDollar = 0;

    if (bills[0] == 10 || bills[0] == 20 || (bills.size() > 1 && bills[1] == 20))
        return false;

    for (int i = 0; i < bills.size(); i++) {
        if (bills[i] == 5) {
            fiveDollar++;
        } 
        else if (bills[i] == 10) {
            if (fiveDollar == 0) return false;
            fiveDollar--;
            tenDollar++;
        } 
        else {
            if (fiveDollar == 0) return false;
            else if (fiveDollar < 3 && tenDollar == 0) return false;

            if (tenDollar == 0)
                fiveDollar -= 3;
            else {
                tenDollar--;
                fiveDollar--;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;  // Number of customers
    vector<int> bills(n);
    for (int i = 0; i < n; i++) cin >> bills[i];

    if (lemonadeChange(bills))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
