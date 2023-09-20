#include "monty.h"

/**
 * parse_line - splits each line of monty into an array of words
 * @str: the line to be splitted
 *
 * Return: the array of words containing the splitted line
 */

char **parse_line(char *str)
{
	char *word, *str_copy;
	char **words;
	int len = 0, i = 0;

	str_copy = strdup(str);

	word = strtok(str, " \n");
	while (word)
	{
		len++;
		word = strtok(NULL, " \n");
	}

	words = malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
	{
		free(str_copy);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	word = strtok(str_copy, " \n");
	while (word)
	{
		words[i] = strdup(word);
		word = strtok(NULL, " \n");
		i++;
	}
	words[i] = NULL;
	free(str_copy);
	return (words);
}

