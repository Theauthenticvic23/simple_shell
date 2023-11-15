#include "cyshell.h"

/**
 * _fhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @finfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _fhistory(finfo_a *finfo)
{
	_fprintlist((*finfo).history);
	return (0);
}

/**
 * unset_falias - sets valias to string
 * @finfo: parameter struct
 * @fstr: the string valias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_falias(finfo_a *finfo, char *fstr)
{
	char *f, c;
	int fret;

	f = _strchr(fstr, '=');
	if (!f)
		return (1);
	c = *f;
	*f = 0;
	fret = fdelete_node_at_ind(&((*finfo).valias),
		get_node_ind((*finfo).valias, fnode_starts_with((*finfo).valias, fstr, -1)));
	*f = c;
	return (fret);
}

/**
 * set_falias - sets valias to string
 * @finfo: parameter struct
 * @fstr: the string valias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_falias(finfo_a *finfo, char *fstr)
{
	char *f;

	f = _strchr(fstr, '=');
	if (!f)
		return (1);
	if (!*++f)
		return (unset_falias(finfo, fstr));

	unset_falias(finfo, fstr);
	return (fadd_node_end(&((*finfo).valias), fstr, 0) == NULL);
}

/**
 * print_falias - prints an valias string
 * @node: the valias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_falias(list_t *node)
{
	char *f = NULL, *a = NULL;

	if (node)
	{
		f = _strchr((*node).fstr, '=');
		for (a = (*node).fstr; a <= f; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(f + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
