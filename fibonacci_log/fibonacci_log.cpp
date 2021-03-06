#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX = 1000;

int f[MAX] = { 0 };

int fib(int n, int m)
{
	//Casos base
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	// Ya se ejecuto
	if (f[n])
		return f[n];

	int k = (n & 1) ? (n + 1) / 2 : n / 2;

// si N es impar o par
	f[n] = (n & 1) ? (((fib(k,m)%m)*(fib(k,m)%m))%m + ((fib((k - 1),m)%m)*(fib((k - 1),m)%m))%m)
		: (2 * (fib((k - 1),m)%m) + ((fib(k,m)%m))*(fib(k,m)%m)%m);

//	f[n] = (n & 1) ? ((fib(k%m )*fib(k%m )) %m + (fib((k - 1)%m )*fib((k - 1)%m ) %m )) : 
//		(2 * fib(k - 1) + fib(k))*fib(k);

	return f[n];
}

int main()
{
	int n = 11, m = 7;
	
	printf("%d ", fib(n,m));
	return 0;
}

