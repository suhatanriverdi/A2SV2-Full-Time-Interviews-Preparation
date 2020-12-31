/*
Calculate a+b for 
-10^1000000 <= a, b <= 10^1000000
+A +B
*/

string sumBigTwoNumbers(string A, string B) {
    int Asize = A.size(), Bsize = B.size(), carry = 0;
    int bigSize = max(Asize, Bsize), smallSize = min(Asize, Bsize);
    if (Asize == 0 || Bsize == 0) {
        return (Asize == 0 ? B : A);
    }
    if (smallSize == B.size()) {
        B.insert(0, (bigSize - smallSize), '0');
    } else {
        A.insert(0, (bigSize - smallSize), '0');
    }
    string result = "";
    for (int i = bigSize - 1; i >= 0; i--) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int sum = a + b + carry;
        int toWrite = sum % 10;
        carry = (sum >= 10 ? 1 : 0);
        result += to_string(toWrite);
    }
    if (carry == 1) {
        result += "1";
    }
    reverse(begin(result), end(result));
    return result;
}

int main() {
    string A = "12345";
    string B = "329";
    string sumResult = "";
    sumResult = sumBigTwoNumbers(A, B);
    cout << "Output: ";
    cout << sumResult;
}