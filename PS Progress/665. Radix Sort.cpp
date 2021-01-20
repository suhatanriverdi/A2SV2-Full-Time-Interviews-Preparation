  
/*
Radix Sort
O(n*k) Time
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

void countingSort(vector<int> &A, int div, int size) {
    vector<int> counts(10, 0), result(size, 0);
    for (int i = 0; i < size; i++) {
        counts[(A[i] / div) % 10]++;
    }
    // Create cumulative array to know actual positions
    for (int i = 1; i < 10; i++) {
        counts[i] += counts[i - 1];
    }
    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        result[counts[(A[i] / div) % 10] - 1] = A[i];
        counts[(A[i] / div) % 10]--;
    }
    // Modify original A with new sorted result
    for (int i = 0; i < size; i++) {
        A[i] = result[i];
    }
}

void radixSort(vector<int> &A) {
    for (int div = 1, maxElement = getMaxElement(A); maxElement / div > 0; div *= 10) {
        countingSort(A, div, A.size());
    }
}

int main() {
    vector<int> A = {124,42,3,1,79,982,22};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    radixSort(A);
    print(A);
}