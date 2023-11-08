#include "shell.h"
/**
 * _pasthistory - displays the history list
 * @format: Structure containing potential
 *  Return: Always 0
 */
int _pasthistory(format_t *format)
{
	print_list(format->history);
	return (0);
}
/**
 * set_alias - string
 * @format: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(format_t *format, char *str)
{
	char *q, b;
	int ret;
	q = _strchr(str, '=');
	if (!q)
		return (1);
	b = *q;
	*q = 0;
	ret = delete_node_at_index(&(format->alias),
		get_node_index(format->alias, node_starts_with(format->alias, str, -1)));
	*q = b;
	return (ret);
}
/**
 * set_alias - sets alias to string
 * @format: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(format_t *format, char *str)
{
	char *w;
	w = _strchr(str, '=');
	if (!w)
		return (1);
	if (!*++w)
		return (unset_alias(format, str));
	set_alias(format, str);
	return (add_node_end(&(format->alias), str, 0) == NULL);
}
/**
 * print_ali - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_ali(list_t *node)
{
	char *f = NULL, *c = NULL;
	if (node)
	{
		f = _strchr(node->str, '=');
		for (c = node->str; c <= f; c++)
		_putchar(*c);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _firstalias - builtin (man alias)
 * @info: Structure 
 *  Return: Always 0
 */
int _firstalias(format_t *format)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;
	if (info->argc == 1)
	{
		node = info->alais;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
