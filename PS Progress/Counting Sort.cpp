/*
Counting Sort
O(n + k) Time
In Place: No
Stable: Yes
*/

int getMaxElement(vector<int> &A) {
    int localMax = A[0];
    for (int n : A) {
        localMax = max(localMax, n);
    }
    return localMax;
}

void print(vector<int> &A) {
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
}

void countingSort(vector<int> &A) {
    int maxElement = getMaxElement(A);
    vector<int> countsArray(maxElement + 1, 0), sortedArray(A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        countsArray[A[i]]++;
    }
    for (int i = 0, sortedIndex = 0; i < countsArray.size(); i++) {
        while (countsArray[i] > 0) {
            sortedArray[sortedIndex] = i;
            countsArray[i]--;
            sortedIndex++;
        }
    }
    A = sortedArray;
}

int main() {
    vector<int> A = {9,4,3,1,7,2,2};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    countingSort(A);
    print(A);
}