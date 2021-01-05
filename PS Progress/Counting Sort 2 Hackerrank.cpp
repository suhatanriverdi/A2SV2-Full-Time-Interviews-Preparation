// Question Link: https://www.hackerrank.com/challenges/countingsort2/problem

vector<int> countingSort(vector<int> arr) {
    if (arr.size() == 0) {
        return {};
    }
    int range = getMaxElement(arr);
    vector<int> countingArray(range + 1, 0), sortedArray(arr.size(), 0);
    // Count all the values in arr
    for (int n : arr) {
        countingArray[n]++;
    }
    // Replace values into sortedArray
    for (int i = 0, sortedIndex = 0; i < countingArray.size(); i++) {
        while (countingArray[i]--) {
            sortedArray[sortedIndex++] = i;
        }
    }
    return sortedArray;
}