// Question Link: https://www.hackerrank.com/challenges/bigger-is-greater/problem

string biggerIsGreater(string w) {
    int toSwapIndex = -1, size = w.size();
    for (int i = size - 2; i >= 0; i--) {
        if (w[i] < w[i + 1]) {
            toSwapIndex = i;
            break;
        }
    }
    if (toSwapIndex == -1) {
        return "no answer";
    }
    // Find next closest greater
    int nextGreaterIndex = toSwapIndex + 1, nextGreaterValue = w[toSwapIndex + 1];
    for (int i = toSwapIndex + 1; i < size; i++) {
        if (w[i] > w[toSwapIndex] && w[i] < nextGreaterValue) {            
            nextGreaterValue = w[i];
            nextGreaterIndex = i;
        }
    }
    swap(w[toSwapIndex], w[nextGreaterIndex]);
    sort(begin(w) + toSwapIndex + 1, end(w));
    return w;
}
