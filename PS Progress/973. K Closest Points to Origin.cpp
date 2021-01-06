// Question Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        vector<pair<double, int>> distances;
        for (int i = 0; i < points.size(); i++) {
            double curDist = findDistanceToTheOrigin(points[i]);
            distances.push_back({curDist, i});
        }
        sort(distances.begin(),distances.end());
        for(int i = 0; i < K ; i++){
            result.push_back(points[distances[i].second]);
        }
        return result;
    }
    
    double findDistanceToTheOrigin(vector<int> &a) {
        double x = (0 - a[0]);
        double y = (0 - a[1]);
        double powSum = pow(x, 2) + pow(y, 2);
        double dist = sqrt(powSum);
        return dist;
    }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> distancesSorted;
        vector<vector<int>> result;
        for (int i = 0; i < points.size(); i++) {
            double curDist = findDistanceToTheOrigin(points[i]);
            distancesSorted.push({curDist, i});
        }
        while (K--) {
            result.push_back(points[distancesSorted.top().second]);
            distancesSorted.pop();
        }
        return result;
    }
    
    double findDistanceToTheOrigin(vector<int> &a) {
        double x = (0 - a[0]);
        double y = (0 - a[1]);
        double powSum = pow(x, 2) + pow(y, 2);
        double dist = sqrt(powSum);
        return dist;
    }
};