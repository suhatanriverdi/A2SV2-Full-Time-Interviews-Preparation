/*
Quick Sort
O(nlogn) Time
In Place: Yes
Stable: No
Divide and Conquer Algorithm
*/

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Pick pivot element
    int s = low - 1; // index of smaller element
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            s++;
            swap(arr[j], arr[s]);
        } 
    }
    swap(arr[high], arr[s + 1]); // Move pivot to correct position
    return s + 1;
}

void print(vector <int> &arr, int low, int high) {
    for (int i = low; i <= high; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void quickSort(vector <int> &arr, int left, int right) {
    if (left < right) {        
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
    vector<int> A = {9,4,3,1,7,2,2};
    cout << "Before Sorting:" << endl;
    print(A, 0, A.size() - 1);
    cout << "After Sorting:" << endl;
    quickSort(A, 0, A.size() - 1);
    print(A, 0, A.size() - 1);
}
