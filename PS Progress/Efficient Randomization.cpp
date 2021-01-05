/*
Efficient Randomization

Input: Numbers from 1 to 10000 in a random order
(you can write a program to generate the input)
Output: 1 2 3 … 10000

Let’s say we want to have each number from 1 to N in a random order.
1) Generate an array of numbers from 1 to N
2) Do following for each position (pos) from N-1 to 1
  a) Generate a random number rn between 0 and pos-1
  b) Swap elements in rn and pos

*/

void print(vector<int> &A) {
    for (int n : A) {
        cout << n << " ";
    }
    cout << endl;
}

// rand() % 100; // in the range 0 to 99
// 25 + (rand() % (63 - 25 + 1)) // in the range 25 to 63
int getRandomNumInRange(int minVal, int maxVal) {
    srand(time(NULL));
    return minVal + (rand() % (maxVal - minVal + 1));
}

vector<int> createInput(int size) {
    vector<int> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = i + 1;
    }
    return result;
}

void efficientRandomization(vector<int> &A) {
    int maxRange = A.size() - 1, tempRandomIndex;
    for (int i = 1; i < A.size(); i++) {
        tempRandomIndex = getRandomNumInRange(i, maxRange);
        swap(A[tempRandomIndex], A[i - 1]);
    }
}

int main() {
    vector<int> A = createInput(10);
    cout << "Input before Shuffling:" << endl;
    print(A);
    cout << "After Shuffling:" << endl;
    efficientRandomization(A);
    print(A);
}