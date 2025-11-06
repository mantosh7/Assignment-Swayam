/*
You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:
Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.
*/

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9} ;
    int k = 3 ;
    int n = stalls.size() ;

    sort(stalls.begin(), stalls.end()) ;
    int low = 0, high = stalls[stalls.size()-1]-stalls[0] ;
    int ans = 1 ;

    while(low <= high)
    {
        int mid = low + (high-low)/2 ;

        int cnt = 1 ;
        int lastAssignedIndex = 0 ;
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-stalls[lastAssignedIndex]  >= mid)
            {
                cnt++ ;
                lastAssignedIndex = i ;
            }
        }
        if(cnt >= k)
        {
            ans = mid ;
            low = mid + 1 ;
        }
        else high = mid - 1 ;
    }
    cout<<ans ;
}