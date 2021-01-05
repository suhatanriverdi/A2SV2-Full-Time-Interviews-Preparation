/*
Counting Sort - With Negatives
O(n^2) Time
In Place: No
Stable: Yes

Try counting sort for inputs that include -ve numbers. 
Eg: -100 to 100
*/

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

int getMinElement(vector<int> &A) {
    int localMin = A[0];
    for (int n : A) {
        localMin = min(localMin, n);
    }
    return localMin;
}

void print(vector<int> &A) {
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
}

void countingSortWithNegatives(vector<int> &A) {
    int maxElement = getMaxElement(A);
    int minElement = getMinElement(A);
    vector<int> countsArrayPositives(maxElement + 1, 0), sortedArrayPosivites;
    vector<int> countsArrayNegatives((-1 * minElement) + 1, 0), sortedArrayNegatives;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= 0) {
            countsArrayPositives[A[i]]++;
        }
        else {
            countsArrayNegatives[A[i] * -1]++;
        }
    }
    for (int i = 0; i < countsArrayPositives.size(); i++) {
        while (countsArrayPositives[i] > 0) {
            sortedArrayPosivites.push_back(i);
            countsArrayPositives[i]--;
        }
    }
    for (int i = 0; i < countsArrayNegatives.size(); i++) {
        while (countsArrayNegatives[i] > 0) {
            sortedArrayNegatives.push_back(i * -1);
            countsArrayNegatives[i]--;
        }
    }
    for (int n : sortedArrayPosivites) {
        sortedArrayNegatives.push_back(n);
    }
    A = sortedArrayNegatives;
}

int main() {
    vector<int> A = {4,-3,0,-1,5,-2,2,-1};
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    countingSortWithNegatives(A);
    print(A);
}