#include "main.h"
/**
 * set_bit - set the value of a bit to 1 at given index
 *
 * @n : the bit to be manipulated
 * @index: position of the bit to be manipulated
 * Return: 1 for succes, -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask;

	if (index > sizeof(unsigned int) * 8)
		return (-1);
	mask = 1;
	mask = mask << index;
	*n = ((*n) | mask);
	return (1);
}
