// Question Link: https://www.hackerrank.com/contests/hw1/challenges/heap-sort/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int root) {
    // Root element is stored at 0
    // If a parent node is at the position I,
    int largest = root;
    // Then Left child is at the position (2*I + 1)
    int left = 2 * root + 1;
    // Right child is at (2*I +2)
    int right = 2 * root + 2;
    // Find max between root, and its children
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // If root is not largest
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n) {
    // Build heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract max elements one by one and move them to the end, reduce the size of heap
    for (int i = n - 1; i >= 0; i--) {
        // Swap elements, move root (max) to the end
        swap(arr[0], arr[i]);
        // Heapify
        heapify(arr, i, 0);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Heapsort array
    heapSort(arr, n);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
             cout << ",";
        }
    }
    cout << "]";
    return 0;
}