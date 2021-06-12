// Merge Sort Implementation

/*
Merge Sort
O(nlogn) Time
In Place: No
Stable: Yes

-> Done Recursively
-> Divide & Conquer

1) Split the array in half until we are left with the single items
                        2 8 5 3 9 4 1 7
                    2 8 5 3         9 4 1 7
                   2 8    5 3     9 4    1 7
                  2   8  5   3   9   4  1   7
          
2) We will compare single items's value and merge them into a a temporary array
2   8   5   3   9   4   1   7
\  /    \  /    \  /    \  /
2,8     3,5      4,9     1,7
  \     /          \     /
  2,3,5,8          1,4,7,9
      \              / 
      1,2,3,4,5,7,8,9
      Array is Sorted
*/

void print(vector<int> &A) {
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
}

// [l to m] and [m+1 to r] in A are sorted
// This functions merges both of these intervals
// Such that interval [l to r] becomes sorted
void merge(vector<int> &A, int l, int mid, int r) {
    vector<int> temp;
    
    int i, j;
    i = l; // Starting index of the first part
    j = mid + 1; // Starting index of the second part
    
    // Start sorting
    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) {
            temp.push_back(A[i]);
            i++;
        }
        else {
            temp.push_back(A[j]);
            j++;
        }
    }
    
    // Get the remaning elements if so
    while (i <= mid) { // first part
        temp.push_back(A[i]);
        i++;
    }
    
    while (j <= r) { // second part
        temp.push_back(A[j]);
        j++;
    }
    
    // Replace sorted interval within the array A
    for (int i = l; i <= r; i++) {
        A[i] = temp[i - l];
    }
}

void mergeSort(vector<int> &A, int l, int r) {
    if (l < r) {
        // Divide the array into two parts
        int mid = l + (r - l) / 2;
        mergeSort(A, l, mid); // Left Part
        mergeSort(A, mid + 1, r); // Right Part
        // Sort & Merge the current part
        merge(A, l, mid, r);
    }
}

int main() {
    vector<int> A = {124,42,3,1,79,982,22};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    mergeSort(A, 0, A.size() - 1);
    print(A);
}