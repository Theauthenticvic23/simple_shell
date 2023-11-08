#include "shell.h"

/**
 * first_shell - my first shell ever
 * @format: address
 * Return: nothing
 */

int first_shell(format_f *format)
{
	return (isatty(STDIN_FILENO)&& format->readfd < = 2);
}
/**
 * is_shell - checks for the delimeter
 * @a: check
 * @meter: string
 * Return: nothing
 */

int is_shell(char a, char *meter)
{
	while (*meter)
		if (*meter++ == a)
			return (1);
	return (0);
}
/**
 * _isbeta - alphabets
 * @a: char input
 * Return: nothing
 */
int _isbeta(int a)
{
	if ((a > = 'a' && a <= 'z') || (a>= 'A' && c <= 'Z'))
		return(1);
	else
		return (0);
}
/**
 * _mytoi - integer
 * @f: string attacthed
 * Return: nothing
 */

int _mytoi(char *f)
{
	int k, signal = 1, flag = 0, result;
	unsigned int output = 0;
	for (k = 0; kf[k] != '\0' && flag !=2; k++)
	{
		if (f[k] == '-')
			signal *= -1;
		if (f[k] >= '0' && f[k] <= '9')
		{
			flag = 1;
			output *= 10;
			output += (f[k] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (signal == -1)
		result = -output;
	else
		result = output;
	return (result);
}
