#include <iostream>
#include <cstring>
#include <windows.h>
#include <time.h>

const int LOOP_COUNT = 512;

template <class T>
void printFormat(const char* format, T arg)
{
	for (int i = 0; i < strlen(format); i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'v':
					std::cout << arg;
					i++;
					break;
				default:
					std::cout << format;
					break;
			}
		}
		else
		{
			std::cout << format[i];
		}
	}
}

template <class T>
void input(T* t)
{
	std::cin >> *t;
}

int main()
{
	srand((unsigned int)time(NULL));
	
	int i, j, k, l;
	
	int x = 5;
	char c = 97;
	char str1[13] = "~@# ^&$ !##@";
	char str2[7] = "  *( )";
	
	std::cout << x << std::endl;
	printFormat("x : %v\n", x);
	printFormat("c : %v\n", c);
	
	int ran = rand() % 10;
	
	printFormat("ran : %v\n>> ", ran);
	
	input(&ran);
	
	while (ran)
	{
		i++;
		j += i * 2;
		k += j * 2;
		l += k * 2;
		
		printFormat("*%v*  _ *    *__ *", l);
	}
	
	return 0;
}
