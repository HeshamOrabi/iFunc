#include "main.h"

/**
 * bultin_env - env buldin command handling
 * @c: strcucture of command
 */
void bultin_env(comd c)
{
	int i = 0;

	c.com = getcomm(c);
	_execve(c);
	if (c.arg[1] == NULL || _strcmp(c.arg[1], "-v") == 0)
	{
		for (; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	if (c.arg[1] != NULL && _strcmp(c.arg[1], "-0") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		}
		write(STDOUT_FILENO, "\n", 1);
	}
	free(c.com);
}

/**
 * bultin_exit - exit bultin command
 * @c: strcture of command info
 */
void bultin_exit(comd c)
{
	int status = 0;

	if (c.arg[1])
		status = _atoi(c.arg[1]);

	free_pointers(c.path, c.arg, NULL);
	exit(status);
}
