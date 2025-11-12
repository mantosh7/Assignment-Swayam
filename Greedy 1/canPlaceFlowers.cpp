#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;

    int i = flowerbed.size() - 1;
    while (i >= 0) {
        if (flowerbed[i] == 1) {
            i -= 2;
        } 
        else if (i - 1 < 0 || (i - 1 >= 0 && flowerbed[i - 1] != 1)) {
            n--;
            if (n == 0) return true;
            flowerbed[i] = 1;
            i -= 2;
        } 
        else {
            i -= 1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> m >> n; // m = size of flowerbed, n = number of flowers to plant
    vector<int> flowerbed(m);
    for (int i = 0; i < m; i++) cin >> flowerbed[i];

    if (canPlaceFlowers(flowerbed, n))
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}
