/*
Search a 2D Matrix
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++) {
        int low = 0, high = col - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] == target)
                return true;
            else if (matrix[i][mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (searchMatrix(matrix, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}


