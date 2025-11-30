#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

void makeTable(double a, double b, double h, ofstream& file) {
    cout << fixed << setprecision(4);
    file << fixed << setprecision(4);

    cout << "x\t\ty(x)\n";
    file << "x\t\ty(x)\n";
    cout << "----------------\n";
    file << "----------------\n";

    for (double x = a; x <= b; x += h) {
        if (fabs(sin(x)) < 0.001 || fabs(cos(x)) < 0.001) {
            cout << x << "\tundefined\n";
            file << x << "\tundefined\n";
        } else {
            double ctg = cos(x) / sin(x);
            double tg = sin(x) / cos(x);
            double y = sqrt(ctg * tg);
            cout << x << "\t" << y << "\n";
            file << x << "\t" << y << "\n";
        }
    }
}

int main() {
    double a, b, h;

    cout << "Enter interval start a: ";
    cin >> a;
    cout << "Enter interval end b: ";
    cin >> b;
    cout << "Enter step h: ";
    cin >> h;

    if (h <= 0) {
        cout << "Error: step must be positive!" << endl;
        return 1;
    }

    if (a > b) {
        cout << "Error: start must be less than end!" << endl;
        return 1;
    }

    ofstream file("result.txt");

    if (!file.is_open()) {
        cout << "Error: failed to create file!" << endl;
        return 1;
    }

    makeTable(a, b, h, file);
    file.close();

    cout << "Results saved to file result.txt" << endl;

    return 0;
}
