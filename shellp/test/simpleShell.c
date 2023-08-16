#include "main.h"

/**
 * main - initializing shell
 * @argc: number of arguments
 * @argv: argument vector
 * @env: enviroment vector
 *
 * Return: 0 of succes
*/
int main(int argc, char *argv[], char *env[])
{
	char init[] = "($) ", fin[] = "^c\n", *buf = NULL, **av;
	pid_t id;
	int gret;
	size_t max_len = 0;
	ssize_t ret;
	bool pipe = false;

	while (gret != -1 && !pipe && argc > 0)
	{
		if (!isatty(STDIN_FILENO))
			pipe = true;
		if (!pipe)
			write(STDOUT_FILENO, init, 4);
		gret = getline(&buf, &max_len, stdin);
		if (gret == -1)
			write(STDOUT_FILENO, fin, 3);
		else
		{
			av = _get_argv(buf);

			id = fork();
			if (id == -1)
				perror(av[0]);
			if (id > 0)
				wait(NULL);
			else
			{
				ret = execve(av[0], av, env);
				if (ret == -1)
				{
					perror(argv[0]);
					kill(getpid(), SIGTERM);
				}
			}
			free(buf);
			buf = NULL;
		}
	}
	return (0);
}
