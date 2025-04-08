#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void z1() {
	double x, y, z;
	cout << "������� 1\n\n������� 3 �����:\n";
	scanf("%lf %lf %lf", &x, &y, &z);
	if (x > y && x > z) {
		cout << "\n���������� ����� " << x << " \n��� ����� 1";
	}
	else if (y > z) {
		cout << "\n���������� ����� " << y << " \n��� ����� 2";
	}
	else {
		cout << "\n���������� ����� " << z << " \n��� ����� 3";
	}
}

void z2() {
	double x, y, z;
	cout << "������� 2\n\n������� 3 �����:\n";
	scanf("%lf %lf %lf", &x, &y, &z);
	if (x > y && x > z) {
		if (y > z) {
			printf("%lf %lf %lf", x, y, z);
		}
		else {
			printf("%lf %lf %lf", x, z, y);
		}
	}
	if (y > x && y > z) {
		if (x > z) {
			printf("%lf %lf %lf", y, x, z);
		}
		else {
			printf("%lf %lf %lf", y, z, x);
		}
	}
	if (z > y && z > x) {
		if (x > y) {
			printf("%lf %lf %lf", z, x, y);
		}
		else {
			printf("%lf %lf %lf", z, y, x);
		}
	}
}

void z3() {
	double a, b, c, n, n1;
	cout << "������� 3\n\n������� 3 �����:\n";
	scanf("%lf %lf %lf", &a, &b, &c);
	n = a - b;
	n1 = a - c;

	if (n < n1) {
		cout << "\n��������� ����� B = " << b << " \n���������� �� � = " << n;
	}
	else {
		cout << "\n��������� ����� C =  " << c << " \n���������� �� � = " << n1;
	}
}

void z4() {
	cout << "������� 4\n\n������� 6 �����:\n";
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	if (x1 == x2)
		x4 = x3;
	else if (x1 == x3)
		x4 = x2;
	else x4 = x1;

	if (y1 == y2)
		y4 = y3;
	else if (y1 == y3)
		y4 = y2;
	else y4 = y1;

	cout << x4 << ", " << y4;
}

void z5() {
	int x;
	double y;
	cout << "������� 5\n\n������� �����:\n";
	scanf("%d", &x);
	if (x < 0) {
		y = -2 * 1.0 / x;
		cout << "\ny =  " << y << " \n";
	}
	else if (x >= 3 && x < 9) {
		y = x * x * x;
		cout << "\ny =  " << y << " \n";
	}
	else if (x >= 9) {
		y = -x * 1.0 / 3;
		cout << "\ny =  " << y << " \n";
	}
	else {
		y = 26.2;
		cout << "\ny =  " << y << " \n";
	}
}

void z6() {
	int x;
	cout << "������� 6\n\n������� �����:\n";
	scanf("%d", &x);
	if (x % 100 == 0 && x % 400 != 0) {
		cout << "\n��� " << x << " - ������������";
	}
	else if (x % 4 == 0) {
		cout << "\n��� " << x << " - ����������";
	}
	else {
		cout << "\n��� " << x << " - ������������";
	}
}

void z7()
{
	cout << "������� 7" << endl;

	int inputValue;
	string daysName[] = { "�����������", "�������", "�����", "�������", "�������", "�������", "�����������" };
	cout << "������� ���� ������ - ����� � ��������� �� 1 �� 7: ";
	cin >> inputValue;

	if (inputValue < 1 || inputValue > 7) {
		cout << "������ �����\n";
	}
	else {
		cout << "���� ���� - " << daysName[inputValue - 1] << endl;
	}
}

void z8()
{
	cout << "������� 8" << endl;

	string direct;
	int com1;
	int com2;
	int sum;

	string corners[] = { "�����", "�����", "��", "������" };
	cout << "������ ����������� � ��� ������� ��������: ";
	cin >> direct;
	cin >> com1;
	cin >> com2;
	sum = abs(com1 + com2);


	if (direct == "�����") {
		sum += 0;
	}
	if (direct == "�����") {
		sum += 1;
	}
	if (direct == "��") {
		sum += 2;
	}
	if (direct == "������") {
		sum += 3;
	}
	sum >= 4 ? sum -= 4 : true;

	cout << "�������� �����������: " << corners[sum] << endl;
}

void z9()
{
	cout << "������� 9" << endl;

	int day;
	int month;

	cout << "������� ����: \n";
	cout << "����: ";
	cin >> day;
	cout << "�����: ";
	cin >> month;


	if (month == 1) {
		if (day >= 20) {
			cout << "�������\n";
		}
		else {
			cout << "�������\n";
		}
	}
	if (month == 2) {
		if (day >= 19) {
			cout << "����\n";
		}
		else {
			cout << "�������\n";
		}
	}
	if (month == 3) {
		if (day >= 21) {
			cout << "����\n";
		}
		else {
			cout << "����\n";
		}
	}
	if (month == 4) {
		if (day >= 19) {
			cout << "�����\n";
		}
		else {
			cout << "����\n";
		}
	}
	if (month == 5) {
		if (day >= 21) {
			cout << "��������\n";
		}
		else {
			cout << "�����\n";
		}
	}
	if (month == 6) {
		if (day >= 22) {
			cout << "���\n";
		}
		else {
			cout << "��������\n";
		}
	}
	if (month == 7) {
		if (day >= 23) {
			cout << "���\n";
		}
		else {
			cout << "���\n";
		}
	}
	if (month == 8) {
		if (day >= 23) {
			cout << "����\n";
		}
		else {
			cout << "���\n";
		}
	}
	if (month == 9) {
		if (day >= 23) {
			cout << "����\n";
		}
		else {
			cout << "����\n";
		}
	}
	if (month == 10) {
		if (day >= 23) {
			cout << "��������\n";
		}
		else {
			cout << "����\n";
		}
	}
	if (month == 11) {
		if (day >= 23) {
			cout << "�������\n";
		}
		else {
			cout << "��������\n";
		}
	}
	if (month == 12) {
		if (day >= 22) {
			cout << "�������\n";
		}
		else {
			cout << "�������\n";
		}
	}

}

int main()
{
	setlocale(LC_ALL, "RUS");

	int number = 1;

	while (number != 0) // ���������� ������ ��������� switch ��� 0
	{
		cout << "������� ����� �������: ";
		cin >> number;

		switch (number)
		{
		case 1:
			z1();
			break;
		case 2:
			z2();
			break;
		case 3:
			z3();
			break;
		case 4:
			z4();
			break;
		case 5:
			z5();
			break;
		case 6:
			z6();
			break;
		default: cout << "��� ������ �������\n";
		}
	}
	return 0;
}