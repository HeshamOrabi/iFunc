/**
 * is_delim - function to check the delim.
 * @c: char in string.
 * @delim: a pointer to the delimiter string.
 * Return: returns 0 or 1
*/
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - a function breaks a string into a tokens
 * @src_string: a pointer to the string.
 * @delim: a pointer to the delimiter string.
 * Return: returns a pointer
*/
char *_strtok(char *src_string, char *delim)
{
	static char *backup_string;
	char *ret;

	if (!src_string)
	{
		src_string = backup_string;
	}
	if (!src_string)
	{
		return (NULL);
	}
	while (1)
	{
		if (is_delim(*src_string, delim))
		{
			src_string++;
			continue;
		}
		if (*src_string == '\0')
		{
			return (NULL);
		}
		break;
	}
	ret = src_string;
	while (1)
	{
		if (*src_string == '\0')
		{
			backup_string = src_string;
			return (ret);
		}
		if (is_delim(*src_string, delim))
		{
			*src_string = '\0';
			backup_string = src_string + 1;
			return (ret);
		}
		src_string++;
	}
}

int main(void)
{
	char str[] = "Hello, World! This is a test string.";
	char delim[] = " ,!.";
	char *token;

	printf("Original string: %s\n", str);
	printf("Delimiter: %s\n", delim);

	token = _strtok(str, delim);
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = _strtok(NULL, delim);
	}

	return 0;
}
