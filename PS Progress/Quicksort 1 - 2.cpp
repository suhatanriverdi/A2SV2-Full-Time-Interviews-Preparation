// Question Link 1: https://www.hackerrank.com/challenges/quicksort1/problem
// Question Link 2: https://www.hackerrank.com/challenges/quicksort2/problem

// Quick Sort 1
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

// Quick Sort 2
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low], i = low; // Pick pivot element
    vector<int> left, right;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            left.push_back(arr[j]);
        } 
        else if (arr[j] > pivot) {
            right.push_back(arr[j]);            
        }
    }
    for (int &l : left) {
        arr[i++] = l;
    }
    int pivotIndex = i;
    arr[i++] = pivot;
    for (int &r : right) {
        arr[i++] = r;
    }
    return pivotIndex;
}

void quickSortHelper(vector <int> &arr, int left, int right) {
    if (left < right) {        
        int pivot = partition(arr, left, right);
        quickSortHelper(arr, left, pivot - 1);
        quickSortHelper(arr, pivot + 1, right);
        print(arr, left, right);
    }
}

void quickSort(vector <int> &arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}
