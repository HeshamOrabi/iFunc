/**
 * _getline - my implemintation of getline
 * @lineptr: a string to but the buffer in it
 * @n: the current str length
 * @fd: the file discreptor
 * Return: returns size of string, or -1 if error
*/
ssize_t _getline(char **lineptr, ssize_t *n, int fd)
{
        static char buffer[BUFF_SIZE];
        static ssize_t buffer_pos;
        static ssize_t buffer_size;
        ssize_t num_read, i;

        if (buffer_pos >= buffer_size)
        {
                buffer_pos = 0;
                buffer_size = read(fd, buffer, _strlen(buffer) + 1);
                if (buffer_size <= 0)
                {
                        return (-1);
                }
        }

        for (num_read = 0; buffer_pos + num_read < buffer_size; num_read++)
        {
                if (buffer[buffer_pos + num_read] == '\n')
                {
                        num_read++;
                        break;
                }
        }

        if (*lineptr == NULL || *n < num_read + 1)
        {
                *lineptr = realloc(*lineptr, num_read + 1);
                if (*lineptr == NULL)
                {
                        return (-1);
                }
                *n = num_read + 1;
        }
        for (i = 0; i < num_read; i++)
        {
                (*lineptr)[i] = buffer[buffer_pos + i];
        }
        (*lineptr)[num_read] = '\0';
        buffer_pos += num_read;
        return (num_read);
}
