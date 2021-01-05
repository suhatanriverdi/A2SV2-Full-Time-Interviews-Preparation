/*
Selection Sort
O(n^2) Time
In Place: Yes
Stable: No
*/

void print(vector<int> &A) {
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] < A[i]) {
                swap(A[j], A[i]);
            }
        }
    }
}

int main() {
    vector<int> A = {9,4,3,1,7,2,2};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    selectionSort(A);
    print(A);
}