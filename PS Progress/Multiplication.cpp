/*
Multiplication
10^1001  *  10^1001
10 ^ 2002
+A +B
-A +B -> Add "-" at the end
+A -B -> Add "-" at the end
-A -B
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

string multiplicationBigTwoNumbers(string A, string B) {
    // Check 0 case
    if (A[0] == '0' || B[0] == '0') {
        return "0";
    }
    // Check 1 case
    if (A == "1" || B == "1") {
        return (A == "1" ? B : A);
    }
    bool isA_negative = (A[0] == '-' ? 1 : 0), isB_negative = (B[0] == '-' ? 1 : 0);
    if (isA_negative) {
        A.erase(0, 1);
    }
    if (isB_negative) {
        B.erase(0, 1);
    }
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    int big = max(A.size(), B.size());
    int small = min(A.size(), B.size()), carry = 0;
    string bigNum = A, smallNum = B; // In case their sizes are equal
    if (A.size() != B.size()) {
        bigNum = (big == A.size() ? A : B), smallNum = (small == A.size() ? A : B);
    }
    string result = "0";
    for (int s = small - 1, addZero = 0; s >= 0; s--, addZero++) {
        string temp = "";
        for (int b = big - 1; b >= 0; b--) {
            int mul = (((bigNum[b] - '0') * (smallNum[s] - '0')) + carry);
            temp += to_string((mul % 10));
            carry = mul / 10;
        }
        if (carry) {
            temp += to_string(carry);
        }
        reverse(begin(temp), end(temp));
        // Add zeros for addition
        temp.append(addZero, '0');
        // Call summation
        result = sumBigTwoNumbers(temp, result);
    }
    // ++ or -- return positive result
    if ((isA_negative && isB_negative) || (!isA_negative && !isB_negative)) {
        return result;
    } 
    // -+ or +- return negative result
    else {
        return "-" + result;
    }
    return result;
}

int main() {
    string A = "90";
    string B = "9";
    string result = "";
    result = multiplicationBigTwoNumbers(A, B);
    cout << "Output: ";
    cout << result;
}