// Question Link: https://www.hackerrank.com/challenges/game-of-two-stacks

int twoStacks(int x, vector<int> a, vector<int> b) {
    int aI = 0, aSize = a.size(), bSize = b.size(), bJ = 0, curSum = 0, result = 0, tmpSteps = 0;
    // Try to get as much nums as possible from Stack A 
    for (; aI < aSize && (a[aI] + curSum) <= x; aI++) {
        curSum += a[aI];
        result++;
        tmpSteps++;
    }
    aI--;
    // Try to get as much nums as possible from Stack B
    while (bJ < bSize && aI < aSize && bJ >= 0) {
        if (b[bJ] + curSum <= x) {
            curSum += b[bJ];
            tmpSteps++;
            bJ++;
        }
        // if we can't get num from Stack B, pop from stack A and try again
        else {
            if (aI >= 0) {
                curSum -= a[aI--];
                tmpSteps--;
            } else {
                break;
            }
        }
        result = max(tmpSteps, result);
    }
    return result;
}