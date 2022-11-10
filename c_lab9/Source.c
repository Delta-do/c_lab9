#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define ROW 9
#define COL 9

int t1_1()
{
	int row, col;
	printf("\n");

	int col1 = 0;
	for (row = 1; row <= ROW; row++)
	{
		col1++;
		for (col = 1; col <= col1; col++)
		{
			printf("%5d", col * row);
		}
		printf("\n");
	}

	return 0;
}

int t1_2()
{
	printf("\n");

	for (int a = 1; a <= 9; a++)
	{
		for (int b = 1; b <= 9; b++)
		{
			printf("%3d x %d = %2d", a, b, a * b);
		}
		printf("\n");
	}

	return 0;
}

int pr_dig(int n)
{
	int p = 1;
	int k = 0;
	int nt = n;
	int dig;

	while (nt != 0)
	{
		k++;
		nt /= 10;
	}
	
	for (int i = 1; i <= k; i++)
	{
		dig = n / (int) pow(10, k - i) % 10;
		printf("%d\n", dig);
		if (dig != 0)
			p *= dig;
	}

	return p;
}

int t2()
{
	int n, res;
	int a;
	while (1)
	{
		printf("Введите целое число, произведение цифр которого нужно вычислить ");
		scanf("%d", &n);
		res = pr_dig(n);
		printf("%d\n", res);

		printf("Продолжить?\n 0 - Да\n Любое число - Нет\n");
		scanf("%d", &a);
		if (a) break;
	}

	return 0;
}

int print_cycle(int kol, char c, char c_end)
{
	for (int i = 0; i < kol; i++)
	{
		printf("%c", c);
	}
	printf("%c", c_end);

	return 0;
}

int t3()
{
	char c;
	int a;
	printf("Введите символ, из которого будет строиться фигура ");
	scanf("%c", &c);
	printf("Введите сторону ");
	scanf("%d", &a);
	a--;

	print_cycle(a / 2 + 3, ' ', c); //первая строка
	puts("");

	for (int i = 0; i <= a / 2; i++) //середина
	{
		print_cycle(a / 2 - i + 1, ' ', c);
		print_cycle(i * 2 + 3, ' ', c);
		puts("");
	}

	for (int i = 0; i < 4 + (a / 2); i++) //последняя строка
	{
		printf("%c", c);
		printf("%c", ' ');
	}

	return 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	//t1_1();

	//t1_2(); //16 вариант

	//t2(); //7 вариант

	t3(); //7 вариант
	
	return 0;
}