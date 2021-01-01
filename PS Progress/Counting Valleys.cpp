// Question Link: https://www.hackerrank.com/challenges/counting-valleys/problem

int countingValleys(int steps, string path) {
    int heigth = 0, result = 0;
    bool inValley = false;
    for (int i = 0; i < steps; i++) {
        if (path[i] == 'U') {
            heigth++;
        } else {
            heigth--;
        }
        // Enters a valley 
        if (inValley == false && heigth == -1) {
            result++;
            inValley = true;
        }
        // Leaves the valley 
        if (inValley == true && heigth == 0) {
            inValley = false;
        }
    }
    return result;
}