/*
875. Koko Eating Bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4
*/

#include<bits/stdc++.h>
using namespace std ;

int main()
{
    vector<int> piles = {30,11,23,4,20} ;
    int h = 6 ;

    int low = 1, high = *max_element(piles.begin(),piles.end()) ;
    int ans = high;
    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;
        long long sum = 0 ;
        for(int i=0;i<piles.size();i++)
        {
            sum += ceil((double)piles[i] / (double)mid);
        }

        if(sum <= h)
        {
            ans = mid ;
            high = mid - 1 ;
        }
        else low = mid + 1 ;
    }
    cout<< ans;
}