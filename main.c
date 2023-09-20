#include "monty.h"

/**
 * main - Entry point to the monty program
 * @ac: argument count to main
 * @av: an array of arguments to main
 *
 * Return: On Success, EXIT_SUCCESS. On failure, EXIT_FAILURE
 */

int main(int ac, char *av[])
{
	FILE *fd;
	int lineno = 0/*, i = 0*/;
	size_t len = 0;
	ssize_t line_read;
	char *line = NULL, **words = NULL;
	stack_t *top = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_read = getline(&line, &len, fd)) != -1)
	{
		lineno++;
		words = parse_line(line);
		if (words)
		{
			if (strcmp(words[0], "push") == 0)
				push(words[1], &top, lineno);
			else
				check_opcode(words[0], lineno, top);
		}
	}

	fclose(fd);
	exit(EXIT_SUCCESS);
}
