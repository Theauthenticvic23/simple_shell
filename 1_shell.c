#include "shell.h"
/**
 * _myfallout - exits the shell
 * @info: Structure 
 * Return: nothing
 */
int _myfallout(format_t *format)
{
	int fallout;
	if (format->argv[1])
	{
		fallout = _erratoi(info->argv[1]);
		if (fallout == -1)
		{
			format->status = 2;
			print_error(format, "Illegal number: ");
			_eputs(format->argv[1]);
			_eputchar('\n');
			return (1);
		}
		format->err_num = _erratoi(format->argv[1]);
		return (-2);
	}
	format->err_num = -1;
	return (-2);
}
/**
 * _myfirst - current directory 
 * @format: structure
 * Return: Always 0
 */
int _myfirst(format_t *format)
{
	char *f, *dir, buffer[1024];
	int chdir_ret;
	f = getcwd(buffer, 1024);
	if (!f)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!format->argv[1])
	{
		dir = _getenv(format, "HOME=");
		if (!dir)
		chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(format, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(format->argv[1], "-") == 0)
	{
		if (!_getenv(format, "OLDPWD="))
		{
			_puts(f);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(format, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(format, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(format->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(format, "can't cd to ");
		_eputs(format->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(format, "OLDPWD", _getenv(format, "PWD="));
		_setenv(format, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _mycode - changes the current directory of the process
 * @format: Structure 
 * Return: Always 0
 */
int _mycode(format_t *format)
{
	char **arg_array;
	arg_array = format->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
