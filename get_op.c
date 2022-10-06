#include "monty.h"

/**
 * get_op - check op against valid opcodes
 * @op: op to check
 * @stack: double pointer to the beginning of the stack
 * @line_no: script line number
 * Return: void
 */
void get_op(char *op, stack_t **stack, unsigned int line_no)
{
	size_t i;
	instruction_t valid_ops[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{NULL, NULL}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, line_no);
			return;
		}
	}
	dprintf(STDOUT_FILENO,
			"L%u: unknown instruction %s\n",
			line_no, op);
	exit(EXIT_FAILURE);
}
