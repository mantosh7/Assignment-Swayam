/*
Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0; i < row; i++) {
        for(int j = i; j < col; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0, k = col - 1; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(matrix);

    for(auto &row : matrix) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
