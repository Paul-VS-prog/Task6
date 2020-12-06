#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
int k;
const int c = 16385; double x[c], y[c];
void KRD(double xA, double yA, double xB, double yB, int k) {
    x[k] = xA;   y[k] = yA;
    x[k + 1] = (2 * xA + xB) / 3; y[k + 1] = (2 * yA + yB) / 3;
    x[k + 2] = (xB + xA) / 2 + (yA - yB) / (2 * sqrt(3.0));
    y[k + 2] = (yB + yA) / 2 + (xB - xA) / (2 * sqrt(3.0));
    x[k + 3] = (xA + 2 * xB) / 3; y[k + 3] = (yA + 2 * yB) / 3;
    x[k + 4] = xB;   y[k + 4] = yB;
}
void F(int n) {
    KRD(-1.0, 0.0, 1.0, 0.0, 0);
    for (int j = 0; j < n; j++) {
        double x1[c], y1[c]; k = pow(4.0, j + 1);
        for (int i = 0; i <= k; i++) {
            x1[i] = x[i]; y1[i] = y[i];
        }
        for (int i = 0; i < k; i++) {
            KRD(x1[i], y1[i], x1[i + 1], y1[i + 1], 4 * i);
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n, cv = 1;
    cout << "Введите глубинну приближения: ";
    cin >> n;
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");
    F(n);
    int um = 100 * n;
    for (int i = 0; i < 4 * k; i++) {
        //cout << x[i] << " " << y[i] << endl << x[i + 1] << " " << y[i + 1];
        if (cv < 16) {
           setcolor(cv);
           cv++;
        }
        else {
            cv = 1;
            setcolor(cv);
        }
        line(x[i] * um, y[i] * um, x[i + 1] * um, y[i + 1] * um);
    }
    readkey();
    closegraph();
}
