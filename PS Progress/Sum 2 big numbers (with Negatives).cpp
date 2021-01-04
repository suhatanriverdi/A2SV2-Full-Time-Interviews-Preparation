/*
Calculate a+b for 
-10^1000000 <= a, b <= 10^1000000
+A +B -> Normal Sum
-A +B
+A -B
-A -B -> remove "-", Normal Sum then put "-" at the end
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
    
    // Remove zeros at the beginning
    int i = 1;
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

int main() {
    string A = "-100000";
    string B = "1";
    string result = "";
    
    result = sumBigTwoNumbersWithNegatives(A, B);
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << " Output: ";
    cout << result;
}