#include <stdio.h>
#include <conio.h>
#include <math.h>

long prod(long, long);
long noOfDigit(long, long);

void main()
{
	long m, n;
	printf("\n-----------------------------------------------");
	printf("\nMULTIPLICATION USING DIVIDE & CONQUER");
	printf("\n-----------------------------------------------");
	printf("\n Enter number1:");
	scanf("%ld", &m);
	printf("\n Enter number2:");
	scanf("%ld", &n);
	printf("\n-----------------------------------------------");
	printf("\n multiplication of %ld and %ld is:%ld", m, n, prod(m, n));
	printf("\n-----------------------------------------------");
}

long prod(long u, long v)
{
	long x, y, w, z;
	long n, m, p1, p2, p3;

	n = noOfDigit(u, v);

	if (u == 0 || v == 0)
	{
		return 0;
	}

	else if (n <= 2)
	{
		return (u * v);
	}

	else
	{
		m = floor(n / 2);

		x = u / pow(10, m);
		w = u % (int)pow(10, m);
		y = v / pow(10, m);
		z = v % (int)pow(10, m);

		p1 = prod(x, w);
		p2 = prod(y, z);
		p3 = prod(x + w, y + z);

		return p1 * pow(10, 2 * m) + (p3 - p1 - p2) * pow(10, m) + p2;
	}
}

long noOfDigit(long m, long n)
{
	long max;
	int b = 0;
	if (m >= n)
		max = m;
	else
		max = n;
	while (max > 0)
	{
		max = max / 10;
		b++;
	}
	return b;
}