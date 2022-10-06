#include "monty.h"

/**
 * m_pop - pop top element off the stack
 * @stack: double pointer to head of stack
 * @line_no: line number of current operation
 * Return: void
 */
void m_pop(stack_t **stack, unsigned int line_no)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		dprintf(STDOUT_FILENO,
				"L%u: can't pop an empty stack\n",
				line_no);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.stack_len--;
}
