// Question Link: https://www.hackerrank.com/challenges/quicksort1/problem

// Complete the quickSort function below.
vector<int> quickSort(vector<int> arr) {
    int pivot = arr[0]; // Pick pivot element
    vector<int> left, right, equal;
    for (int &n : arr) {
        if (n < pivot) {
            left.push_back(n);
        } 
        else if (n == pivot) {
            equal.push_back(n);
        }
        else {
            right.push_back(n);            
        }
    }
    arr.clear();
    while (left.size() > 0) {
        arr.push_back(left.back());
        left.pop_back();
    }
    while (equal.size() > 0) {
        arr.push_back(equal.back());
        equal.pop_back();
    }
    while (right.size() > 0) {
        arr.push_back(right.back());
        right.pop_back();
    }
    return arr;
}
