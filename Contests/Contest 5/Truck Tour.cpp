// Question Link: https://www.hackerrank.com/challenges/truck-tour/problem

int truckTour(vector<vector<int>> P) {
    int curPetrol = 0, curStop = 0, firstStopAnswer = 10e5 + 1, size = P.size();
    while (curStop < size) {
        curPetrol += P[curStop][0];
        // We cannot get to the next pump station
        if (curPetrol < P[curStop][1]) {
            // Reset current petrol
            curPetrol = 0;
            // Reset possible answer
            firstStopAnswer = 10e5 + 1;
        } 
        // Possible answer
        else {
            firstStopAnswer = min(firstStopAnswer, curStop);
            curPetrol -= P[curStop][1];
        }
        // If we reach the end of the array
        if (curStop == size - 1) {
            return firstStopAnswer;
        }
        curStop++;           
    }
    return size - 1;
}