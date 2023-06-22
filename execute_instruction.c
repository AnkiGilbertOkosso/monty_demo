#include "monty.h"
/**
* execute_instruction - executes the opcode
* @stack: head linked list - stack
* @line_counter: line_counter
* @file: poiner to monty file
* @element: line element
* Return: no return
*/
int execute_instruction(char *element, stack_t **stack, unsigned int line_counter, FILE *file)
{
	instruction_t ints[] = {
				{"push", __push},
                {"pall", __pall},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(element, " \n\t");
	if (op && op[0] == '#')
		return (0);
	interpreter.line = strtok(NULL, " \n\t");
	while (ints[i].opcode && op)
	{
		if (strcmp(op, ints[i].opcode) == 0)
		{	ints[i].f(stack, line_counter);
			return (0);
		}
		i++;
	}
	if (op && ints[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, op);
		fclose(file);
		free(element);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
* free_stack - frees a doubly linked list
* @head: head of a stack
*/
void free_stack(stack_t *head)
{
	stack_t *stack;

	stack = head;
	while (head)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}
