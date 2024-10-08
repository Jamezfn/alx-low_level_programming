#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all the elements of a dlistint_t list.
 * @h: pointer the head of the doubly linked list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *buf;

	buf = h;
	while (buf != NULL)
	{
		printf("%d\n", buf->n);
		buf = buf->next;
		count++;
	}
	return (count);
}
