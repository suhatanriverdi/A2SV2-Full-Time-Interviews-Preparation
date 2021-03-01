// Question Link: https://www.hackerrank.com/challenges/lilys-homework/problem

int lilysHomework(vector<int> arr) {
    vector<int> sortedINC = arr;
    vector<int> sortedDESC = arr;
    vector<int> arr2 = arr;
    sort(begin(sortedINC), end(sortedINC)); // 1 2 3 4
    sort(begin(sortedDESC), end(sortedDESC), greater<int>()); // 4 3 2 1
    unordered_map<int, int> valIdxMapINC, valIdxMapDESC;// {val, its idx in sorted order}
    // Get sorted indices for INC
    for (int i = 0; i < sortedINC.size(); i++) {
        valIdxMapINC[sortedINC[i]] = i;
    }
    // Get sorted indices for DESC
    for (int i = 0; i < sortedDESC.size(); i++) {
        valIdxMapDESC[sortedDESC[i]] = i;
    }
    int szI = 0, szD = 0, size = arr.size() - 1;
    // Inc
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != sortedINC[i]) {
            swap(arr[i], arr[valIdxMapINC[arr[i]]]);
            szI++;
            i--;
        }
    }
    // Desc
    for (int i = 0; i < arr2.size(); i++) {
        if (arr2[i] != sortedDESC[i]) {
            swap(arr2[i], arr2[valIdxMapDESC[arr2[i]]]);
            szD++;
            i--;
        }
    }
    return min(szI, szD);
}