#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

double Perymetr(double x, double y) {  // Завдання 1
	return 2 * (abs(x) + abs(y));
}

double Plosca(double x, double y) {  // Завдання 1
	return abs(x) * abs(y);
}

int Sign(double x) {  // Завдання 2
	if (x < 0)
		return -1;

	else if (x == 0) 
		return 0;

	else if (x > 0)
		return 1;

}

int SumRange(int a, int b) {  // Завдання 3
	int sum = 0;
	if (a > b) {
		return 0;
	}
	for (int i = a; i <= b; ++i) {
		sum += i;
		cout << sum << " ";
	}
	return sum;
}

int Quarter(double x, double y) {  // Завдання 4
	if (x > 0 && y > 0) {
		return 1;
	}
	else if (x < 0 && y > 0) {
		return 2;
	}
	else if (x < 0 && y < 0) {
		return 3;
	}
	else if (x > 0 && y < 0) {
		return 4;
	}
	else {
		return 0;
	}
}

bool Even(int k) {  // Завдання 5
	return k % 2 == 0;
}

double Leng(double x1, double y1, double x2, double y2) {  // Завдання 6
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main()
{
	int in, Sign_x, Sign_res, Even_count = 0;
	double C_x, C_y, Per, Pl, Quarter_x1, Quarter_y1, Quarter_x2, Quarter_y2, Quarter_x3, Quarter_y3, Leng_x1, Leng_y1, Leng_x2, Leng_y2;
	vector<int> Even_arr(10);
	srand(time(0));
	system("chcp 1251");
    while (true) {
		cout << "1. Знаходження периметра і площі прямокутника" << endl;
        cout << "2. Sign повертає -1, 0 або 1" << endl;
        cout << "3. Знайти суму цілих чисел" << endl;
		cout << "4. Визначити номер кординатной чверті" << endl;
		cout << "5. Парне чи непарне" << endl;
		cout << "6. Визначення довжини відрізка на площині" << endl;
		cout << "0. Вихід" << endl;
		cin >> in;

		if (in == 0) {
			return 0;
		}

		switch (in) {
		case 1:
			cout << endl;
			cout << "Введіть координати вершини C (x, y): ";
			cin >> C_x >> C_y;

			Per = Perymetr(C_x, C_y);
			Pl = Plosca(C_x, C_y);

			cout << "Периметр прямокутника: " << Per << endl;
			cout << "Площа прямокутника: " << Pl << endl;
			break;
		case 2:
			cout << endl;
			cout << "Введіть число: ";	
			cin >> Sign_x;
			Sign_res = Sign(Sign_x);
			cout << "Sign(" << Sign_x << ") = " << Sign_res << endl;
			break;
		case 3:
			cout << endl;
			cout << "1. Вводити з клавіатури" << endl;
			cout << "2. Вивести в діапазоні 20 - 30" << endl;
			int in2;

			cin >> in2;

			switch (in2) {
			case 1:
				int a, b;
				cout << endl;
				cout << "Введіть діапазон чисел: ";
				cin >> a >> b;
				cout << "Сума чисел в діапазоні: " << SumRange(a, b) << endl;
				break;
			case 2:
				cout << "Сума чисел в діапазоні: " << SumRange(20, 30) << endl;
				break;
			default:
				cout << "Невірний вибір" << endl;
				break;
			}
			break;
		case 4:
			cout << endl;
			cout << "Введіть координати першої точки (x1, y1): ";
			cin >> Quarter_x1 >> Quarter_y1;

			cout << "Введіть координати другої точки (x2, y2): ";
			cin >> Quarter_x2 >> Quarter_y2;

			cout << "Введіть координати третьої точки (x3, y3): ";
			cin >> Quarter_x3 >> Quarter_y3;

			cout << "Перша точка знаходиться в " << Quarter(Quarter_x1, Quarter_y1) << "-й чверті." << endl;
			cout << "Друга точка знаходиться в " << Quarter(Quarter_x2, Quarter_y2) << "-й чверті." << endl;
			cout << "Третя точка знаходиться в " << Quarter(Quarter_x3, Quarter_y3) << "-й чверті." << endl;

			break;
		case 5:
			cout << endl;
			cout << "Згенеровані числа: \n";
			for (int i = 0; i < 10; i++) {
				Even_arr[i] = rand() % 100;
				cout << Even_arr[i] << " ";
				if (Even(Even_arr[i])) {
					Even_count++;
				}
			}

			cout << "\nКількість парних чисел: " << Even_count << endl;
			Even_count = 0;
			break;
		case 6:
			cout << endl;
			cout << "Введіть координати першої точки (x1, y1): ";
			cin >> Leng_x1 >> Leng_y1;
			cout << "Введіть координати другої точки (x2, y2): ";
			cin >> Leng_x2 >> Leng_y2;

			cout << "Довжина відрізка: " << Leng(Leng_x1, Leng_y1, Leng_x2, Leng_y2) << endl;
			break;
		default:
			cout << "Невірний вибір" << endl;
			break;
		}
    }
}

