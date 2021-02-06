// Question Link: https://www.hackerrank.com/contests/a2sv-contest-4/challenges/qheap1/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q, tmp;
    set<int> minHeap;
    cin >> n;
    while (n--) {
        cin >> q;
        // Add
        if (q == 1) {
            cin >> tmp;
            minHeap.insert(tmp);
        } 
        // Remove
        else if (q == 2) {
            cin >> tmp;
            minHeap.erase(tmp);
        }
        // Print
        else {
            cout << *minHeap.begin() << endl;
        }
    }
    return 0;
}
