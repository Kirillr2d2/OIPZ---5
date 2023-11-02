#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("te5.txt");
void dataNChecking(int n) //���� ������ ��� �������� n
{
	setlocale(LC_ALL, "UKRAINIAN");
	if (n < 3)
	{
		throw "����������� �������� n";
	}
}
void dataBChecking(double b, double x) //���� ������ ��� �������� b
{
	setlocale(LC_ALL, "UKRAINIAN");
	if (b < x)
	{
		throw "����������� �������� b, b ������� ���� ����� �� a ��� ���������� a";
	}
}
void dataHChecking(int h) //���� ������ ��� �������� h
{
	setlocale(LC_ALL, "UKRAINIAN");
	if (h <= 0)
	{
		throw "����������� �������� h, h ������� ���� ����� �� 0";
	}
}
void Value(int& n, double& x, double& b, double& h, double& YesOrNo) //���� ������� ��� ��������� ����� � �� ���������
{
	setlocale(LC_ALL, "UKRAINIAN");
	cout << "���� ������� �������� ����������, �������� 1: ";
	cin >> YesOrNo;
	cout << "n ������� ���� >= 3: ";
	cin >> n;
	dataNChecking(n);
	cout << "b ������� ���� >= a: ";
	double a;
	cin >> a;
	x = a;
	cout << "b >= a: ";
	cin >> b;
	dataBChecking(b, x);
	cout << "h ������� ���� ����� 0: ";
	cin >> h;
	dataHChecking(h);
}
double calculator(int n, double x) ///���� ������� ��� ����������� �������
{
	if (x <= 0) // 1 ����
	{
		double HelpValue = 0;
		for (int i = 2; i <= n - 1; i++)
		{
			HelpValue += x / i;
		}
		return HelpValue;
	}
	else // 2 ����
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
	try // ��������
	{
		Value(n, x, b, h, YesOrNo); // ��������� ������� � �������� ������
	}
	catch (const char* exit) // ���� �������� ���������
	{
		cout << exit;
		return -1;
	}
	catch (...) // ���� �������� ��������� �� ������� �� �� ���
	{
		cout << "������� �������";
		return -2;
	}
	for (x; x <= b; x += h) // ���� ������� �������
	{
		static int counter = 1;
		cout << "���������" << counter << " (x=" << x << ")" << ": " << calculator(n, x) << endl;
		if (YesOrNo == 1)
		{
			fout << "���������" << counter << " (x=" << x << ")" << ": " << calculator(n, x) << endl;
		}
		counter++;

	}
	return 1;
}
