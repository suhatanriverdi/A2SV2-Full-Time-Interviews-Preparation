// Question Link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem

int getMedian(vector<int> &counts, int mid, int &d) {
    int mid2 = mid - 1, median;
    // Mid for both cases
    for (int i = 0; i < counts.size() && mid; i++) {
        if (counts[i] > 0) {
            if (counts[i] >= mid) {
                median = i; // i * 2
                break;
            } 
            else {
                mid -= counts[i];  
            }
        }
    }
    // If Even
    if (d % 2 == 0) {
        // Mid2 for even case
        for (int i = 0; i < counts.size() && mid; i++) {
            if (counts[i] > 0) {
                if (counts[i] >= mid2) {
                    median += i;
                    break;
                } 
                else {
                    mid2 -= counts[i];  
                }
            }
        }
    } 
    // If Odd
    else {
        median *= 2;
    }
    return median;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    vector<int> counts(201, 0);
    for (int i = 0; i < d; i++) {
        counts[expenditure[i]]++;
    }
    int result = 0, left = 0;
    for (int cur = d; cur < expenditure.size(); cur++) {
        int median = getMedian(counts, (d / 2) + 1, d);
        if (expenditure[cur] >= median) {
           result++; 
        }
        counts[expenditure[cur]]++;
        counts[expenditure[left]]--;
        left++;
    }
    return result;
}
