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
            cout << x << "\tne opredeleno\n";
            file << x << "\tne opredeleno\n";
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

    cout << "Vvedite nachalo intervala a: " << std::flush;
    if (!(cin >> a)) {
        cout << "Oshibka vvoda dlya a! Vvedite chislo." << endl;
        return 1;
    }
    
    cout << "Vvedite konec intervala b: " << std::flush;
    if (!(cin >> b)) {
        cout << "Oshibka vvoda dlya b! Vvedite chislo." << endl;
        return 1;
    }
    
    cout << "Vvedite shag h: " << std::flush;
    if (!(cin >> h)) {
        cout << "Oshibka vvoda dlya h! Vvedite chislo." << endl;
        return 1;
    }

    // Ensure input/output streams are synchronized
    cin.sync();

    if (h <= 0) {
        cout << "Oshibka: shag dolzhen byt polozhitelnym!" << endl;
        return 1;
    }

    if (a > b) {
        cout << "Oshibka: nachalo dolzhno byt menshe konca!" << endl;
        cout << "a = " << a << ", b = " << b << endl; // Покажем что ввел пользователь
        return 1;
    }

    ofstream file("result.txt");

    if (!file.is_open()) {
        cout << "Oshibka: ne udalos sozdat fail!" << endl;
        return 1;
    }

    makeTable(a, b, h, file);
    file.close();

    cout << "Rezultaty sohraneny v fail result.txt" << std::flush;
    cout << "Najmite Enter dlya vyhoda..." << std::flush;
    cin.ignore();
    cin.get();

    return 0;
}
