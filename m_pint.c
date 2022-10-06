#include "monty.h"

/**
 * m_pint - pint value on top of the stack or exit if stack is empty
 * @stack: double pointer to head of stack
 * @line_no: line number of current operation
 * Return: void
 */
void m_pint(stack_t **stack, unsigned int line_no)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't pint, stack empty\n",
				line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
