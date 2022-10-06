#include "monty.h"

/**
 * check_for_digit - checks that a string only contains digits
 * @arg: string to check
 * Return: 0 if only digits, else 1
 */
static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * m_push - push an int onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_no: script line number
 * Return: void
 */
void m_push(stack_t **stack, unsigned int line_no)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
				"L%u: usage: push integer\n",
				line_no);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
/**
 * m_pall - print all values on the 'stack' starting from the top
 * @stack: double pointer to the head of the stack
 * @line_no: line number being executed from script file
 * Return: void
 */

void m_pall(stack_t **stack, unsigned int line_no __attribute__((unused)))
{
	stack_t *head;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
