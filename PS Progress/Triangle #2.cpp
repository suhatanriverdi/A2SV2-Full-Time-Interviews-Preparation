void triangle2Iterative(int n) {
    int numOfStars = 1;
    int numOfSpaces = n - 1;
    for (int i = 0; i < n; i++) {
        // Put spaces
        for (int j = 0; j < numOfSpaces; j++) {
            cout << " ";
        }
        // Put stars
        for (int s = 0; s < numOfStars; s++) {
            cout << "*";
        }
        numOfStars += 2;
        numOfSpaces -= 1;
        cout << endl;
    }
}

void triangle2Recursive(int n, int numOfStars, int numOfSpaces) {
    if (n == 0) {
        return;
    }
    // Put spaces
    for (int j = 0; j < numOfSpaces; j++) {
        cout << " ";
    }
    // Put stars
    for (int s = 0; s < numOfStars; s++) {
        cout << "*";
    }
    cout << endl;
    triangle2Recursive(n - 1, numOfStars + 2, numOfSpaces - 1);
}

int main() {
    int n = 5;
    // cout << "Output Iterative:" << endl;
    // triangle2Iterative(n);
    cout << "Output Recursive:" << endl;
    triangle2Recursive(n, 1, n - 1);
}