#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO_stat(int stat, int fd, char *filename, char mode);

/**
 * main - function that copies the content of a file to another file
 * @argc: the argument count
 * @argv: the argument passed
 * Return: 1 on success, otherwise exit
 */
int main(int argc, char *argv[])
{
	int src, dest, n_read = 1024, wrote, close_src, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = open(argv[1], O_RDONLY);
	check_IO_stat(src, -1, argv[1], 'o');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(dest, -1, argv[2], 'w');
	while (n_read == 1024)
	{
		n_read = read(src, buffer, sizeof(buffer));
			if (n_read == -1)
				check_IO_stat(-1, src, argv[1], 'r');
		wrote = write(dest, buffer, n_read);
		if (wrote == -1)
			check_IO_stat(-1, dest, argv[2], 'w');
	}
	close_src = close(src);
	check_IO_stat(close_src, src, NULL, 'c');
	close_dest = close(dest);
	check_IO_stat(close_dest, dest, NULL, 'c');
	return (0);
}

/**
 * check_IO_stat - functions checks if a file can be opened or closed
 * @stat: status of the file operation
 * @fd: file descriptor
 * @filename: name of the file
 * @mode: opening or closing mode
 * Return: void
 */
void check_IO_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'c' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'r' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(98);
	}
	else if (mode == 'w' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
