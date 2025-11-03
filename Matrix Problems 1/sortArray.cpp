/*
Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    vector<int> temp;
    int left = l;
    int right = mid + 1;

    while (left <= mid && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int length = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}