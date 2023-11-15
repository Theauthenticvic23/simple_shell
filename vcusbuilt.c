#include "cyshell.h"

/**
 * _myvalias - mimics the valias builtin (man valias)
 * @finfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myvalias(finfo_a *finfo)
{
	int i = 0;
	char *f = NULL;
	list_t *node = NULL;

	if ((*finfo).argc == 1)
	{
		node = (*finfo).valias;
		while (node)
		{
			print_valias(node);
			node = (*node).next;
		}
		return (0);
	}
	for (i = 1; (*finfo).argv[i]; i++)
	{
		f = _strchr((*finfo).argv[i], '=');
		if (f)
			set_valias(finfo, (*finfo).argv[i]);
		else
			print_valias(fnode_starts_with((*finfo).valias, (*finfo).argv[i], '='));
	}

	return (0);
}

/**
 * _vexit - exits the shell
 * @finfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if finfo.argv[0] != "exit"
 */
int _vexit(finfo_a *finfo)
{
	int fexitcheck;

	if ((*finfo).argv[1])  /* If there is an exit arguement */
	{
		fexitcheck = _ferratoi((*finfo).argv[1]);
		if (fexitcheck == -1)
		{
			(*finfo).status = 2;
			print_error(finfo, "Illegal number: ");
			_fputs((*finfo).argv[1]);
			_fputchar('\n');
			return (1);
		}
		(*finfo).err_num = _ferratoi((*finfo).argv[1]);
		return (-2);
	}
	(*finfo).err_num = -1;
	return (-2);
}

/**
 * _vcd - changes the current directory of the process
 * @finfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _vcd(finfo_a *finfo)
{
	char *s, *fdir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!(*finfo).argv[1])
	{
		fdir = _vgetenv(finfo, "HOME=");
		if (!fdir)
			chdir_ret = /* TODO: what should this be? */
				chdir((fdir = _vgetenv(finfo, "PWD=")) ? fdir : "/");
		else
			chdir_ret = chdir(fdir);
	}
	else if (_strcmp((*finfo).argv[1], "-") == 0)
	{
		if (!_vgetenv(finfo, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_vgetenv(finfo, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((fdir = _vgetenv(finfo, "OLDPWD=")) ? fdir : "/");
	}
	else
		chdir_ret = chdir((*finfo).argv[1]);
	if (chdir_ret == -1)
	{
		print_error(finfo, "can't cd to ");
		_fputs((*finfo).argv[1]), _fputchar('\n');
	}
	else
	{
		_fsetenv(finfo, "OLDPWD", _vgetenv(finfo, "PWD="));
		_fsetenv(finfo, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _vhelp - changes the current directory of the process
 * @finfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _vhelp(finfo_a *finfo)
{
	char **arg_array;

	arg_array = (*finfo).argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
