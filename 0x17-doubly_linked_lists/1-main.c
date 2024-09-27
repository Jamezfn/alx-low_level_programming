#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - Main function to test doubly linked list operations
 *
 * Return: Always EXIT_SUCCESS on success, or EXIT_FAILURE if an error occurs
 */
int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	dlistint_t hello = {8, NULL, NULL};
	size_t n;

	head = &hello;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->n = 9;
	head->prev = new;
	new->prev = head;
	new->prev = NULL;
	head = new;

	n = dlistint_len(head);
	printf("-> %lu elements\n", n);

	free(new);
	return (EXIT_SUCCESS);
}

