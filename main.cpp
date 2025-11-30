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
        // Проверяем особые точки (где sin(x)=0 или cos(x)=0)
        if (fabs(sin(x)) < 0.001 || fabs(cos(x)) < 0.001) {
            cout << x << "\tне опр.\n";
            file << x << "\tне опр.\n";
        }
        else {
            // Вычисляем функцию: y(x) = sqrt(ctg(x)*tg(x))
            double ctg = cos(x) / sin(x);
            double tg = sin(x) / cos(x);
            double y = sqrt(ctg * tg);
            cout << x << "\t" << y << "\n";
            file << x << "\t" << y << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, h;

    cout << "Введите начало интервала a: ";
    cin >> a;
    cout << "Введите конец интервала b: ";
    cin >> b;
    cout << "Введите шаг h: ";
    cin >> h;

    if (h <= 0) {
        cout << "Ошибка: шаг должен быть положительным!" << endl;
        return 1;
    }

    if (a > b) {
        cout << "Ошибка: начало должно быть меньше конца!" << endl;
        return 1;
    }

    ofstream file("result.txt");

    if (!file.is_open()) {
        cout << "Ошибка: не удалось создать файл!" << endl;
        return 1;
    }

    makeTable(a, b, h, file);
    file.close();

    cout << "Результаты сохранены в файл result.txt" << endl;

    return 0;
}
