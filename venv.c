#include "cyshell.h"

/**
 * _venv - prints the current environment
 * @finfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _venv(finfo_a *finfo)
{
	fprint_list_str((*finfo).env);
	return (0);
}

/**
 * _vgetenv - gets the value of an environ variable
 * @finfo: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_vgetenv(finfo_a *finfo, const char *name)
{
	list_t *node = (*finfo).env;
	char *f;

	while (node)
	{
		f = fstarts_with((*node).fstr, name);
		if (f && *f)
			return (f);
		node = (*node).next;
	}
	return (NULL);
}

/**
 * _vmsetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @finfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _vmsetenv(finfo_a *finfo)
{
	if ((*finfo).argc != 3)
	{
		_fputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_fsetenv(finfo, (*finfo).argv[1], (*finfo).argv[2]))
		return (0);
	return (1);
}

/**
 * _vunsetenv - Remove an environment variable
 * @finfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _vunsetenv(finfo_a *finfo)
{
	int i;

	if ((*finfo).argc == 1)
	{
		_fputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= (*finfo).argc; i++)
		f_unsetenv(finfo, (*finfo).argv[i]);

	return (0);
}

/**
 * vpop_env_list - populates env linked list
 * @finfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int vpop_env_list(finfo_a *finfo)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		fadd_node_end(&node, environ[i], 0);
	(*finfo).env = node;
	return (0);
}
