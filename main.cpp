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

	for (double x = a; x <= b; x += h){
		if (fabs(sin(x)) < 0.001 || fabs(cos(x)) < 0.001){
			cout << x << "\tne opredeleno\n";
			file << x << "\tne opredeleno\n";
		}
		else{
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

	cout << "Vvedite nachalo intervala a: ";
	cin >> a;
	cout << "Vvedite konec intervala b: ";
	cin >> b;
	cout << "Vvedite shag h: ";
	cin >> h;

	// Проверяем, что ввод прошел успешно
	if (cin.fail()) {
		cout << "Oshibka vvoda! Vvedite chisla." << endl;
		return 1;
	}

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

	cout << "Rezultaty sohraneny v fail result.txt" << endl;
	cout << "Najmite Enter dlya vyhoda...";
	cin.ignore();
	cin.get();

	return 0;
}
