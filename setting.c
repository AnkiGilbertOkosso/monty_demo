#include "monty.h"

/**
 * addnode - add node to head stack
 * @head: head of a stack
 * @new: new_value
 * Return: no return
*/
void addnode(stack_t **head, int new)
{

	stack_t *start, *stack;

	stack = *head;
	start = malloc(sizeof(stack_t));
	if (start == NULL)
	{
        printf("Error\n");
		exit(0);
    }
	if (stack)
		stack->prev = start;
	start->n = new;
	start->next = *head;
	start->prev = NULL;
	*head = start;
}


/**
 * addqueue - add node to tail stack
 * @new: new_value
 * @head: head of stack
 * Return: no return
*/
void addqueue(stack_t **head, int new)
{
	stack_t *start, *stack;

	stack = *head;
	start = malloc(sizeof(stack_t));
	if (start == NULL)
	{
		printf("Error\n");
	}
	start->n = new;
	start->next = NULL;
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	if (!stack)
	{
		*head = start;
		start->prev = NULL;
	}
	else
	{
		stack->next = start;
		start->prev = stack;
	}
}
