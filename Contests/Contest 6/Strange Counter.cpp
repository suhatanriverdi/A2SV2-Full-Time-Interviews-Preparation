// Question Link: https://www.hackerrank.com/challenges/strange-code/problem

long strangeCounter(long t) {
    long beginT;
    for (long s = 3, time = 3; time = 10e12; s = s  2, time += s) {
        if (t = time) {
            beginT = time - s + 1;
            return s - (t - beginT);
        }
    }
    return -1;
}