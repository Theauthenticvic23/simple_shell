#ifndef _SHELL_H_
#define _SHELL_H_
int first_shell(format_f *format);
int is_shell(char a, char *meter);
int _isbeta(int a);
int _mytoi(char *f);
int _myfallout(format_t *format);
int _myfirst(format_t *format);
int _mycode(format_t *format);
int _pasthistory(format_t *format);
int print_ali(list_t *node);
int unset_alias(format_t *format, char *str);
int _firstalias(format_t *format);
int set_alias(format_t *format, char *str);

#endif
