/*
Bubble Sort
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

void bubbleSort(vector<int> &A) {
    bool swapped = true;
    int lastUnsortedElementIndex = A.size() - 1;
    while (swapped) {
        swapped = false;
        for (int i = 1; i <= lastUnsortedElementIndex; i++) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                swapped = true;
            }
        }
        lastUnsortedElementIndex--;
    }
}

int main() {
    vector<int> A = {9,4,3,1,7,2,2};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    bubbleSort(A);
    print(A);
}
