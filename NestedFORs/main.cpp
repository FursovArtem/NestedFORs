#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

#define delimiter "------------------------------------------------------------------------------------------------------------------------\n"

//1. ������ ������� ���������
void smooth_multi_columns()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << std::setw(2) << i << " * " << std::setw(2) << j << " = " << std::setw(3) << i * j << endl;
		}
		cout << endl;
	}
	cout << delimiter;
}
//������ ������ ������������ ������� ��������� (������ 1) ����� if else ��� std::setw
void if_else_multi_columns()
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			int answer = i * j;
			if (i < 10 && j < 10 && answer < 10)
			{
				cout << " " << i << " *  " << j << " =   " << answer << endl;
			}
			else if (i < 10 && j < 10 && answer < 100)
			{
				cout << " " << i << " *  " << j << " =  " << answer << endl;
			}
			else if (i != 10 && j == 10)
			{
				cout << " " << i << " * " << j << " =  " << answer << endl;
			}
			else if (i == 10 && j != 10)
			{
				cout << i << " *  " << j << " =  " << answer << endl;
			}
			else
			{
				cout << i << " * " << j << " = " << answer << endl;
			}
		}
		cout << endl;
	}
	cout << delimiter;
}

//2. ������� ��������
void pythagoras_table()
{
	cout << std::setw(34) << "2. ������� ��������" << endl;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 51; j++)
		{
			cout << "-";
		}
		cout << endl;
		for (int j = 1; j < 11; j++)
		{
			cout << "|" << std::setw(3) << j * i << " ";
		}
		cout << endl;
	}
	cout << delimiter;
}

//3. 4. ��� ���������
int fibonacci(int num)
{				//������� ��������� ����� � ���������� ����� � ���� ��������� ��� ���� ������� (������� � 0)
	int buffer_1 = 0;
	int element = 1;	//�������� ���� ��������� ���������� �������� 1 ��� ����, ����� �� �������
	//�� ��������� ���� ������� ������ �� ������ ���� ���� - �������)
	if (num == 0)
	{							//���� - ������ ����� ���� �, �� ��� �� ���������� ������� � ����, ������� ��� ����
		return 0;			//����� �������� ��������� ������� (������� ���� � ������� ����� ���������� � ����)
	}
	else
	{												//��� ������ ���� ���� ���� - 0 � 1 - ����������� ������� ��������� ������
		for (int i = 2; i <= num; i++)	//��� ��������� ����� (������� � �������, i = 2 �.�. ������ � ����) �����
		{											//��������� ����� � ������� ���� ������������� ����������
			int buffer_2 = buffer_1 + element;
			buffer_1 = element;
			element = buffer_2;
		}
		return element;
	}
}
void fibonacci_value_limited()
{
	cout << "3. ��� ��������� �� ��������� ����������� ��������" << endl;
	int fibonacci_limit;
	cout << "������� ���������� ��������, ����� ��������� ������������ �� �����: "; cin >> fibonacci_limit;
	for (int i = 0; i < INFINITY; i++)			//���� ����������� �.�. �� ������� ����� ������������ ���������
	{															//����� �, � �� �� ����������� (��� � ��������� ������)
		if (fibonacci(i) > fibonacci_limit)
		{
			break;
		}
		cout << fibonacci(i) << "\t ";
	}
	cout << endl << delimiter;
}
void fibonacci_set_amount()
{
	cout << "4. ����� ���������, �������� ���������� (� int ���������� �������� 47 ����)" << endl;
	int fibonacci_amount;
	cout << "������� ���������� ����� ���������: "; cin >> fibonacci_amount;
	for (int i = 0; i < fibonacci_amount; i++)
	{
		cout << i + 1 << "-� �����: " << fibonacci(i) << endl;
	}
	cout << delimiter;
}

//5. ������� �����
inline void prime_numbers_limited()
{
	cout << "5. ������� ����� �� ���������� �������" << endl;
	int prime_limit;
	bool check = true;
	cout << "������� ������, ������� ����� ������������ ��: "; cin >> prime_limit;
	for (int i = 2; i <= prime_limit; i++)		//0 � 1 - �� ������� �����, ������� �� 2
	{
		for (int j = 2; j <= i / 2; j++)	//j - ��� ��� ��������� �������� ��� i - �� 2 �� i/2 (����� ����� �� �����������
		{				//����� �� i, ��� ����� ������ �������� � ��������� ����� �������� � ��������� ��� �������)
			if (i % j == 0)
			{
				check = false;		//���� ���������� ����-�� ���� �������� ������ ��� �������, �� ��� ���
				break;					//�� ������� �����, ������� ���������� false � ���� ��������� ���������
			}
		}
		if (check)						//���� �� ���� �������� �� 2 �� i/2 �� ������� ������ - ��� ������� �����
		{
			cout << i << "\t ";
		}
		check = true;				//���� ����� ���� ���������, � check ���� �������� false, �������
		//����� ����� ������� ��� ���� true � ��������� ��������, ����� ���
	}										//��������� �������� ����� ������������, �.�. �������� ��������� false
	cout << endl << delimiter;
}

void main()
{
	setlocale(LC_ALL, "");
	//1.
	smooth_multi_columns();
	//if_else_multi_columns();
	//2.
	pythagoras_table();
	//3. 4.
	fibonacci_value_limited();
	fibonacci_set_amount();
	//5.
	prime_numbers_limited();
}
