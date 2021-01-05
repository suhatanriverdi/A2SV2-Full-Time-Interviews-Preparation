/*
Insertion Sort
O(n^2) Time
In Place: Yes
Stable: Yes
*/

void print(vector<int> &A) {
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &A) {
    for (int i = 1; i < A.size(); i++) {
        int key = A[i], j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    vector<int> A = {9,4,3,1,7,2,2};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    insertionSort(A);
    print(A);
}