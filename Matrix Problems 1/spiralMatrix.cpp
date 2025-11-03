/*
Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> v;
    int minRow = 0, maxRow = m - 1;
    int minCol = 0, maxCol = n - 1;

    while (minRow <= maxRow && minCol <= maxCol) {
        for (int i = minCol; i <= maxCol && minRow <= maxRow; i++)
            v.push_back(matrix[minRow][i]);
        minRow++;

        for (int i = minRow; i <= maxRow && minCol <= maxCol; i++)
            v.push_back(matrix[i][maxCol]);
        maxCol--;

        for (int i = maxCol; i >= minCol && minRow <= maxRow; i--)
            v.push_back(matrix[maxRow][i]);
        maxRow--;

        for (int i = maxRow; i >= minRow && minCol <= maxCol; i--)
            v.push_back(matrix[i][minCol]);
        minCol++;
    }

    return v;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> result = spiralOrder(matrix);

    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
