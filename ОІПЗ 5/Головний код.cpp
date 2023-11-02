#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("te5.txt");
void dataNChecking(int n) //нова фунція для перевірки n
{
	setlocale(LC_ALL, "UKRAINIAN");
	if (n < 3)
	{
		throw "Неправильне значення n";
	}
}
void dataBChecking(double b, double x) //нова фунція для перевірки b
{
	setlocale(LC_ALL, "UKRAINIAN");
	if (b < x)
	{
		throw "Неправильне значення b, b повинно бути більше за a або дорівнювати a";
	}
}
void dataHChecking(int h) //нова фунція для перевірки h
{
	setlocale(LC_ALL, "UKRAINIAN");
	if (h <= 0)
	{
		throw "Неправильне значення h, h повинно бути більше за 0";
	}
}
void Value(int& n, double& x, double& b, double& h, double& YesOrNo) //нова функція для отримання даних з іх перевіркою
{
	setlocale(LC_ALL, "UKRAINIAN");
	cout << "Якщо потрібно записати результати, натисніть 1: ";
	cin >> YesOrNo;
	cout << "n повинно бути >= 3: ";
	cin >> n;
	dataNChecking(n);
	cout << "b повинно бути >= a: ";
	double a;
	cin >> a;
	x = a;
	cout << "b >= a: ";
	cin >> b;
	dataBChecking(b, x);
	cout << "h повинно бути більше 0: ";
	cin >> h;
	dataHChecking(h);
}
double calculator(int n, double x) ///нова функція для знаходження значень
{
	if (x <= 0) // 1 сума
	{
		double HelpValue = 0;
		for (int i = 2; i <= n - 1; i++)
		{
			HelpValue += x / i;
		}
		return HelpValue;
	}
	else // 2 суми
	{
		double HelpValue = 0;
		for (int i = 0; i <= n - 1; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				HelpValue += i / (j + x);
			}
		}

		return HelpValue;
	}
}
int main()
{
	setlocale(LC_ALL, "UKRAINIAN");
	int n;
	double x, b, h, YesOrNo;
	try // перевірка
	{
		Value(n, x, b, h, YesOrNo); // отримання значень у головнку фунцію
	}
	catch (const char* exit) // якщо перевірка провальна
	{
		cout << exit;
		return -1;
	}
	catch (...) // якщо перевірка провальна та невідомо що не так
	{
		cout << "Невідома помилка";
		return -2;
	}
	for (x; x <= b; x += h) // цикл основної функції
	{
		static int counter = 1;
		cout << "Результат" << counter << " (x=" << x << ")" << ": " << calculator(n, x) << endl;
		if (YesOrNo == 1)
		{
			fout << "Результат" << counter << " (x=" << x << ")" << ": " << calculator(n, x) << endl;
		}
		counter++;

	}
	return 1;
}
