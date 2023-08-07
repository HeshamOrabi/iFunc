#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *create_buff(char *argv);
int edit_close(int fd);

int main(int argc, char *argv[])
{
	int fd_source, fd_dist, cr, cw;
	char *buff;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_source = open(argv[1], O_RDONLY);
	fd_dist = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	buff = create_buff(argv[1]);

	do
	{
		cr = read(fd_source, buff, 1024);
		if (cr == -1 || fd_source == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", argv[2]);
			exit(98);
		}

		cw = write(fd_dist, buff, cr);
		if (cw == -1 || fd_dist == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[3]);
			exit(99);
		}

		fd_dist = open(argv[2], O_WRONLY | O_APPEND);
	} while (cr > 0);

	free(buff);
	edit_close(fd_source);
	edit_close(fd_dist);

	return (0);
}

int edit_close(int fd)
{
	int cc;

	cc = close(fd);
	if (cc == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}

	return (0);
}

char *create_buff(char *argv)
{
	char *cp;

	cp = malloc(1024);
	if (cp == NULL)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv);
		exit(98);
	}

	return (cp);
}
