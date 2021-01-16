// Question Link: https://www.hackerrank.com/contests/a2sv2/challenges/bon-appetit

// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
    int sumAnnaAte = 0;
    for (int i = 0; i < bill.size(); i++) {
        sumAnnaAte += bill[i];
    }
    sumAnnaAte -= bill[k];
    int bActual = sumAnnaAte / 2;
    if (bActual == b) {
        cout << "Bon Appetit" << endl;
    } else {
        cout << b - bActual << endl;
    }
}