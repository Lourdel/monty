#include "monty.h"

/**
 * m_add - adds the top elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_no: script line number
 * Return: void
 */
void m_add(stack_t **stack, unsigned int line_no)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't add, stack too short\n",
				line_no);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	m_pop(stack, line_no);
	(*stack)->n += n;
}
