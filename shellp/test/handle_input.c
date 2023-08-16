#include "main.h"

/**
 * _get_argv - make the argument vector
 * @buf: the buffered input
 *
 * Return: argumet vector array of strings
*/
char **_get_argv(char *buf)
{
	char **argv;
	int i = 0;
	char *cmp = strdup(buf);
	char *token = strtok(buf, " \n");

	while (token)
	{
		token = strtok(NULL, " \n");
		i++;
	}

	argv = malloc(sizeof(char *) * i);
	i = 0;
	token = strtok(cmp, " \n");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
