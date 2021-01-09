/*
Assume the division is a valid division. And for Positive numbers only.
Division
10^1000 10^999
10
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

bool findNegativeBigOne(string &A, string &B) {
    // Find negative one
    bool isA_negative = (A[0] == '-' ? 1 : 0), isB_negative = (B[0] == '-' ? 1 : 0);
    string bigNum;
    if (isA_negative) {
        A.erase(0, 1);
    } else {
        B.erase(0, 1);
    }
    int big = (A.size() > B.size() ? A.size() : B.size());
    if (A.size() != B.size()) {
        bigNum = (A.size() == big ? A : B);
    } 
    // If sizes are equal, find bigger num witout considersing the "-" sign
    else {
        for (int i = 0; i < big; i++) {
            if (A[i] != B[i]) {
                bigNum = (A[i] > B[i] ? A : B);
                break;
            }
        }
    }
    // Check if A is bigger
    if ((A == bigNum && isA_negative) || (B == bigNum && isB_negative)) {
        // Put "-" to the result
        return true;
    } 
    return false;
}

void getTensFromLeftNeighbors(string &bigNum, int pos) {
    int i = pos - 1;
    for (; i >= 0; i--) {
        // If digit has some value, we take it
        if ((bigNum[i] - '0') > 0) {
            int tmp = (bigNum[i] - '0');
            tmp--;
            char c = '0' + tmp;
            bigNum[i] = c;
            i++;
            break;
        }
    }
    for (; i < pos; i++) {
        // If digit has some value, we take it
        if (bigNum[i] == '0') {
            bigNum[i] = '9';
        }
    }
}
    
string sumBigTwoNumbersWithNegatives(string A, string B) {
    string Aoriginal = A, Boriginal = B;
    if (A == "0" || B == "0") {
        return (A == "0" ? B : A);
    }
    bool isA_negative = (A[0] == '-' ? 1 : 0), isB_negative = (B[0] == '-' ? 1 : 0);
    if (isA_negative) {
        A.erase(0, 1);
    }
    if (isB_negative) {
        B.erase(0, 1);
    }
    // -12 <> 12
    if (A == B) {
        return "0";
    }
    // ++ or --
    if ((isA_negative && isB_negative) || (!isA_negative && !isB_negative)) {
        return (isA_negative ? ("-" + sumBigTwoNumbers(A, B)) : sumBigTwoNumbers(A, B));
    }
    // -+ or +- case
    int big = (A.size() > B.size() ? A.size() : B.size());
    int small = (A.size() < B.size() ? A.size() : B.size());
    string bigNum = A, smallNum = B;
    if (A.size() != B.size()) {
        bigNum = (A.size() == big ? A : B);
        smallNum = (B.size() == small ? B : A);
        smallNum.insert(0, (big - small), '0');
    } 
    // If sizes are equal, find bigger num witout considersing the "-" sign
    else {
        for (int i = 0; i < small; i++) {
            if (A[i] != B[i]) {
                bigNum = (A[i] > B[i] ? A : B);
                smallNum = (A[i] < B[i] ? A : B);
                break;
            }
        }
    }
    string result = "";
    for (int i = big - 1; i >= 0; i--) {
        // Needs 10s from left side
        if ((bigNum[i] - '0') < (smallNum[i] - '0')) {
            getTensFromLeftNeighbors(bigNum, i);
            result += to_string(((bigNum[i] - '0') + 10) - (smallNum[i] - '0'));
        }
        else {
            result += to_string((bigNum[i] - '0') - (smallNum[i] - '0'));
        }
    }
    reverse(result.begin(), result.end());
    // Remove zeros at the beginning,
    int i = 0;
    if (result[0] == '-') {
        i = 1;
    }
    for (; i < result.size() && result[i] == '0'; i++) {};
    string resultNoZeros;
    for (int j = i; j < result.size(); j++) {
        resultNoZeros += result[j];
    }
    // string Aoriginal = A, Boriginal = B;
    if (findNegativeBigOne(Aoriginal, Boriginal)) {
        return "-" + resultNoZeros;
    }
    return resultNoZeros;
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

// quotient <= dividend
bool isSmallerOrEqualTo(string &quotient, string &Dividend) {
    if (quotient.size() < Dividend.size()) {
        return true;   
    }
    if (quotient.size() == Dividend.size()) {
        for (int i = 0; i < quotient.size(); i++) {
            if (quotient[i] != Dividend[i]) {
                if ((quotient[i] - '0') > (Dividend[i] - '0')) {
                    return false;
                } else {
                    break;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

// A is dividend, B is divisor
string divisionBigTwoNumbers(string A, string B) {
    if (A == B) {
        return "1";
    }
    string curQuotient = "1";
    string temp = multiplicationBigTwoNumbers(B, curQuotient);
    cout << "temp: " << temp << endl;
    while (isSmallerOrEqualTo(temp, A)) {
        curQuotient = sumBigTwoNumbers(curQuotient, "1");
        temp = multiplicationBigTwoNumbers(B, curQuotient);
    }
    cout << curQuotient << endl;
    return sumBigTwoNumbersWithNegatives("-1", curQuotient);
}

int main() {
    string A = "32145";
    string B = "21";
    string result = "";
    result = divisionBigTwoNumbers(A, B);
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "Output: ";
    cout << result;
}
