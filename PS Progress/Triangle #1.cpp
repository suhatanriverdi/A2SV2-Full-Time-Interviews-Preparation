void triangle1Iterative(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void triangle1Recursive(int n) {
    if (n == 0) {
        return;
    }
    triangle1Recursive(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

int main() {
    int n = 5;
    cout << "Output Iterative:" << endl;
    triangle1Iterative(n);
    cout << "Output Recursive:" << endl;
    triangle1Recursive(n);
}