// Question Link: https://www.hackerrank.com/contests/a2sv-contest-3/challenges/jesse-and-cookies

int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int &c : A) {
        PQ.push(c);
    }
    int steps = 0;
    while (!PQ.empty()) {
        if (PQ.top() >= k) {
            return steps;
        }
        int cur = PQ.top(), tmp = 0, cur2;
        PQ.pop();
        tmp += cur;
        if (!PQ.empty()) {
            cur2 = PQ.top();
            PQ.pop();
            tmp += cur2 * 2;
        } else {
            return -1;
        }
        PQ.push(tmp);
        steps++;
    }
    return (PQ.top() >= k ? steps : -1);
}