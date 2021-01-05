/*
Counting Sort - 2
O(n^2) Time
In Place: No
Stable: Yes

If sorting an object with some specified key;
E.g. sorting dessert object (which have type and price) with price;
1- Initialize counter array with empty arrays ([ [],[],[],[] ]), its size is the range of the keys (in this case, range of prices)
2- Iterate over the input, insert object at corresponding index in counter array
3- Iterate over counter array and build output.
*/

// Dessert Object
class Dessert {
public:
    int price;
    char type;
};

int getMaxElement(vector<Dessert> &A) {
    int localMax = A[0].price;
    for (Dessert n : A) {
        localMax = max(localMax, n.price);
    }
    return localMax;
}

void print(vector<Dessert> &A) {
    cout << "Type\t" << "Price" << endl;
    for (Dessert n : A) {
        cout << n.type << "\t" << n.price << endl;
    }
    cout << endl;
}

void countingSort(vector<Dessert> &A) {
    int maxElement = getMaxElement(A);
    vector<vector<Dessert>> countsArray(maxElement + 1, vector<Dessert>());
    vector<Dessert> sortedArray(A.size());
    for (int i = 0; i < A.size(); i++) {
        countsArray[A[i].price].push_back(A[i]);
    }
    for (int i = 0, sortedIndex = 0; i < countsArray.size(); i++) {
        while (countsArray[i].size() > 0) {
            sortedArray[sortedIndex] = countsArray[i].back();
            countsArray[i].pop_back();
            sortedIndex++;
        }
    }
    A = sortedArray;
}

int main() {
    vector<Dessert> A = {
        {3, 'a'},
        {1, 'b'},
        {2, 'c'},
        {3, 'f'},
        {5, 'd'},
    };
    cout << "Before Sorting:" << endl;
    print(A);
    cout << "After Sorting:" << endl;
    countingSort(A);
    print(A);
}