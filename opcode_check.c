#include "monty.h"

/**
 * check_opcode - checks a specific opcode and executes it's corresponding
 * function
 * @str: the opcode
 * @lineno: the line number currently being read
 * @stack: the stack
 *
 * Return: Nothing
 */

void check_opcode(char *str, int lineno, stack_t *stack)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL},
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, str) == 0)
		{
			(opcodes[i].f)(&stack, lineno);
			return;
		}
		i++;
	}

	dprintf(2, "L%d: unknown instruction %s\n", lineno, str);
	exit(EXIT_FAILURE);
}
