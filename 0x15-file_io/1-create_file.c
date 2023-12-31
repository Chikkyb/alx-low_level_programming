#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_desc, write_result, lenght = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenght = 0; text_content[lenght];)
			lenght++;
	}

	file_desc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_result = write(file_desc, text_content, lenght);

	if (file_desc == -1 || write_result == -1)
		return (-1);

	close(file_desc);

	return (1);
}
