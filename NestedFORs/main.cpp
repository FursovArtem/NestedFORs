#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

#define delimiter "------------------------------------------------------------------------------------------------------------------------\n"

//1. Ровная таблица умножения
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
//Первая версия выравнивания таблицы умножения (задача 1) через if else без std::setw
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

//2. Таблица Пифагора
void pythagoras_table()
{
	cout << std::setw(34) << "2. Таблица Пифагора" << endl;
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

//3. 4. Ряд Фибоначчи
int fibonacci(int num)
{				//Функция принимает номер и возвращает число в ряду Фибоначчи под этим номером (начиная с 0)
	int buffer_1 = 0;
	int element = 1;	//элементу ряда Фибоначчи изначально присвоим 1 для того, чтобы не попадая
	//во вложенный цикл вывести вторую из первых двух цифр - единицу)
	if (num == 0)
	{							//ноль - первая цифра ряда Ф, но его не получается вложить в цикл, поэтому для него
		return 0;			//здесь отведено отдельное условие (главный цикл в задачах будет начинаться с нуля)
	}
	else
	{												//для первых двух цифр ряда - 0 и 1 - специальные условия прописаны сверху
		for (int i = 2; i <= num; i++)	//все остальные цифры (начиная с третьей, i = 2 т.к. отсчет с нуля) будут
		{											//считаться здесь с помощью двух промежуточных переменных
			int buffer_2 = buffer_1 + element;
			buffer_1 = element;
			element = buffer_2;
		}
		return element;
	}
}
void fibonacci_value_limited()
{
	cout << "3. Ряд Фибоначчи до заданного предельного значения" << endl;
	int fibonacci_limit;
	cout << "Введите предельное значение, числа Фибоначчи включительно до числа: "; cin >> fibonacci_limit;
	for (int i = 0; i < INFINITY; i++)			//цикл бесконечный т.к. по условию нужно ограничиться значением
	{															//числа Ф, а не их количеством (как в следующей задаче)
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
	cout << "4. Числа Фибоначчи, заданное количество (в int помещается максимум 47 штук)" << endl;
	int fibonacci_amount;
	cout << "Введите количество чисел Фибоначчи: "; cin >> fibonacci_amount;
	for (int i = 0; i < fibonacci_amount; i++)
	{
		cout << i + 1 << "-е число: " << fibonacci(i) << endl;
	}
	cout << delimiter;
}

//5. Простые числа
inline void prime_numbers_limited()
{
	cout << "5. Простые числа до указанного предела" << endl;
	int prime_limit;
	bool check = true;
	cout << "Введите предел, простые числа включительно до: "; cin >> prime_limit;
	for (int i = 2; i <= prime_limit; i++)		//0 и 1 - не простые числа, поэтому от 2
	{
		for (int j = 2; j <= i / 2; j++)	//j - это все возможные делители для i - от 2 до i/2 (лучше взять до квадратного
		{				//корня из i, так будет меньше проверок и программа будет работать в несколько раз быстрее)
			if (i % j == 0)
			{
				check = false;		//если встретился хотя-бы один делитель нацело без остатка, то это уже
				break;					//не простое число, поэтому записываем false и идем проверять следующее
			}
		}
		if (check)						//если ни один делитель от 2 до i/2 не поделил нацело - это простое число
		{
			cout << i << "\t ";
		}
		check = true;				//если число было составное, в check было записано false, поэтому
		//здесь нужно вернуть как было true к следующей итерации, иначе все
	}										//следующие проверки будут бессмысленны, т.к. навсегда останется false
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
